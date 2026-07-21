#!/usr/bin/env python3
import argparse
import html
from html.parser import HTMLParser
import json
import os
import re
import sys
import urllib.error
import urllib.request
from pathlib import Path


GRAPHQL_URL = "https://leetcode.com/graphql"
DEFAULT_OUTPUT_DIR = Path(
    "/home/loki/Documents/all_program_app_1/all_program_app/language scripts/LEET_CODE/CODES"
)
ENV_FILE = ".leetcode_sync.env"

EXTENSIONS = {
    "bash": "sh",
    "c": "c",
    "cpp": "cpp",
    "csharp": "cs",
    "dart": "dart",
    "elixir": "ex",
    "erlang": "erl",
    "golang": "go",
    "java": "java",
    "javascript": "js",
    "kotlin": "kt",
    "mysql": "sql",
    "php": "php",
    "python": "py",
    "python3": "py",
    "racket": "rkt",
    "ruby": "rb",
    "rust": "rs",
    "scala": "scala",
    "swift": "swift",
    "typescript": "ts",
}

COMMENT_PREFIXES = {
    "bash": "#",
    "mysql": "--",
    "python": "#",
    "python3": "#",
    "racket": ";",
    "ruby": "#",
}


class ProblemHtmlParser(HTMLParser):
    def __init__(self) -> None:
        super().__init__()
        self.parts: list[str] = []

    def handle_starttag(self, tag: str, attrs: list[tuple[str, str | None]]) -> None:
        if tag in {"p", "pre", "ul", "ol", "li"}:
            self._newline()
        if tag == "li":
            self.parts.append("- ")
        if tag == "sup":
            self.parts.append("^")
        if tag == "br":
            self._newline()

    def handle_endtag(self, tag: str) -> None:
        if tag in {"p", "pre", "ul", "ol", "li"}:
            self._newline()

    def handle_data(self, data: str) -> None:
        text = html.unescape(data.replace("\xa0", " "))
        if text.strip():
            self.parts.append(text)

    def _newline(self) -> None:
        if self.parts and not self.parts[-1].endswith("\n"):
            self.parts.append("\n")

    def text(self) -> str:
        raw = "".join(self.parts)
        lines = []
        for line in raw.splitlines():
            cleaned = re.sub(r"\s+", " ", line).strip()
            if cleaned:
                lines.append(cleaned)
            elif lines and lines[-1] != "":
                lines.append("")
        return "\n".join(lines).strip()


def load_env(path: Path) -> None:
    if not path.exists():
        return
    for raw_line in path.read_text(encoding="utf-8").splitlines():
        line = raw_line.strip()
        if not line or line.startswith("#") or "=" not in line:
            continue
        key, value = line.split("=", 1)
        os.environ.setdefault(key.strip(), value.strip().strip('"').strip("'"))


def graphql(query: str, variables: dict, session: str, csrf: str) -> dict:
    payload = json.dumps({"query": query, "variables": variables}).encode("utf-8")
    request = urllib.request.Request(
        GRAPHQL_URL,
        data=payload,
        headers={
            "Content-Type": "application/json",
            "Referer": "https://leetcode.com/",
            "User-Agent": "leetcode-local-sync/1.0",
            "Cookie": f"LEETCODE_SESSION={session}; csrftoken={csrf}",
            "x-csrftoken": csrf,
        },
        method="POST",
    )
    try:
        with urllib.request.urlopen(request, timeout=30) as response:
            body = response.read().decode("utf-8")
    except urllib.error.HTTPError as exc:
        message = exc.read().decode("utf-8", errors="replace")
        raise RuntimeError(f"LeetCode HTTP {exc.code}: {message}") from exc
    except urllib.error.URLError as exc:
        raise RuntimeError(f"Could not reach LeetCode: {exc.reason}") from exc

    data = json.loads(body)
    if data.get("errors"):
        raise RuntimeError(json.dumps(data["errors"], indent=2))
    return data["data"]


def get_username(session: str, csrf: str) -> str:
    data = graphql(
        """
        query userStatus {
          userStatus {
            isSignedIn
            username
          }
        }
        """,
        {},
        session,
        csrf,
    )
    status = data["userStatus"]
    if not status.get("isSignedIn") or not status.get("username"):
        raise RuntimeError("Cookie is not signed in. Refresh cookies from the browser and try again.")
    return status["username"]


def recent_accepted(username: str, limit: int, session: str, csrf: str) -> list[dict]:
    data = graphql(
        """
        query recentAcSubmissions($username: String!, $limit: Int!) {
          recentAcSubmissionList(username: $username, limit: $limit) {
            id
            title
            titleSlug
            timestamp
          }
        }
        """,
        {"username": username, "limit": limit},
        session,
        csrf,
    )
    return data["recentAcSubmissionList"]


def submission_details(submission_id: str, session: str, csrf: str) -> dict:
    data = graphql(
        """
        query submissionDetails($submissionId: Int!) {
          submissionDetails(submissionId: $submissionId) {
            code
            lang {
              name
            }
            runtime
            memory
            statusDisplay
            timestamp
            question {
              questionId
              title
              titleSlug
            }
          }
        }
        """,
        {"submissionId": int(submission_id)},
        session,
        csrf,
    )
    return data["submissionDetails"]


def question_details(title_slug: str, session: str, csrf: str) -> dict:
    data = graphql(
        """
        query questionDetails($titleSlug: String!) {
          question(titleSlug: $titleSlug) {
            content
            difficulty
            exampleTestcases
            topicTags {
              name
            }
          }
        }
        """,
        {"titleSlug": title_slug},
        session,
        csrf,
    )
    return data["question"]


def safe_name(value: str) -> str:
    return re.sub(r"[^a-zA-Z0-9._-]+", "-", value).strip("-").lower()


def difficulty_dir(problem: dict) -> str:
    difficulty = problem.get("difficulty") or "Unknown"
    if difficulty in {"Easy", "Medium", "Hard"}:
        return difficulty
    return "Unknown"


def file_for_submission(details: dict, problem: dict, output_dir: Path) -> Path:
    question = details["question"]
    lang = details["lang"]["name"]
    ext = EXTENSIONS.get(lang, lang)
    question_id = question["questionId"]
    slug = safe_name(question["titleSlug"])
    return output_dir / difficulty_dir(problem) / f"{question_id}.{slug}.{ext}"


def html_to_text(content: str) -> str:
    parser = ProblemHtmlParser()
    parser.feed(content or "")
    return parser.text()


def comment_prefix(lang: str) -> str:
    return COMMENT_PREFIXES.get(lang, "//")


def comment_lines(text: str, prefix: str) -> str:
    result = []
    for line in text.splitlines():
        if line:
            result.append(f"{prefix} {line}".rstrip())
        else:
            result.append(prefix)
    return "\n".join(result)


def code_with_header(details: dict, problem: dict) -> str:
    question = details["question"]
    lang = details["lang"]["name"]
    prefix = comment_prefix(lang)
    tags = ", ".join(tag["name"] for tag in problem.get("topicTags", [])) or "N/A"
    statement = html_to_text(problem.get("content", ""))
    examples = (problem.get("exampleTestcases") or "").strip()
    header = [
        f"LeetCode {question['questionId']}. {question['title']}",
        f"Difficulty: {problem.get('difficulty') or 'N/A'}",
        f"Tags: {tags}",
        f"Status: {details['statusDisplay']}",
        f"Language: {lang}",
        f"Runtime: {details.get('runtime') or 'N/A'}",
        f"Memory: {details.get('memory') or 'N/A'}",
        f"URL: https://leetcode.com/problems/{question['titleSlug']}/",
        "",
        "Question:",
        statement or "N/A",
    ]
    if examples:
        header.extend(["", "Example Testcases:", examples])
    return (
        f"{comment_lines(chr(10).join(header), prefix)}\n\n"
        f"{details['code'].rstrip()}\n"
    )


def main() -> int:
    parser = argparse.ArgumentParser(description="Sync accepted LeetCode website submissions locally.")
    parser.add_argument("--limit", type=int, default=20, help="How many recent accepted submissions to pull.")
    parser.add_argument("--output-dir", type=Path, default=DEFAULT_OUTPUT_DIR)
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    load_env(Path(__file__).with_name(ENV_FILE))
    session = os.environ.get("LEETCODE_SESSION", "").strip()
    csrf = os.environ.get("LEETCODE_CSRFTOKEN", "").strip() or os.environ.get("csrftoken", "").strip()

    if not session or not csrf:
        print(
            "Missing cookies. Put LEETCODE_SESSION and LEETCODE_CSRFTOKEN in "
            f"{Path(__file__).with_name(ENV_FILE)}",
            file=sys.stderr,
        )
        return 2

    username = get_username(session, csrf)
    submissions = recent_accepted(username, args.limit, session, csrf)
    if not submissions:
        print(f"No accepted submissions found for {username}.")
        return 0

    for folder in ("Easy", "Medium", "Hard"):
        (args.output_dir / folder).mkdir(parents=True, exist_ok=True)
    changed = 0
    for item in submissions:
        details = submission_details(item["id"], session, csrf)
        if details["statusDisplay"] != "Accepted":
            continue
        problem = question_details(details["question"]["titleSlug"], session, csrf)
        path = file_for_submission(details, problem, args.output_dir)
        path.parent.mkdir(parents=True, exist_ok=True)
        content = code_with_header(details, problem)
        if path.exists() and path.read_text(encoding="utf-8") == content:
            print(f"OK unchanged {path.name}")
            continue
        changed += 1
        if args.dry_run:
            print(f"WOULD SAVE {path}")
        else:
            path.write_text(content, encoding="utf-8")
            print(f"SAVED {path}")

    print(f"Synced {len(submissions)} submissions for {username}; {changed} file(s) changed.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
