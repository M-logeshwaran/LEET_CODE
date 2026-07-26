// LeetCode 3. Longest Substring Without Repeating Characters
// Difficulty: Medium
// Tags: Hash Table, String, Sliding Window
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 11020000
// URL: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
// Question:
// Given a string s, find the length of the longestsubstring without duplicate characters.
// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
// Constraints:
// - 0 <= s.length <= 5 * 10^4
// - s consists of English letters, digits, symbols and spaces.
//
// Example Testcases:
// "abcabcbb"
// "bbbbb"
// "pwwkew"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1);
        int max_Len = 0;
        int start = 0;
        
        for (int end = 0; end < s.size(); end++) {
            char current_char = s[end];
            if (lastIndex[current_char] >= start) {
                start = lastIndex[current_char] + 1;
            }
            lastIndex[current_char] = end;
            max_Len = max(max_Len, end - start + 1);
        }
        
        return max_Len;
    }
};
