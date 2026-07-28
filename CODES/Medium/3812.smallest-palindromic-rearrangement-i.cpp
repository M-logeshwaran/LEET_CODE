// LeetCode 3812. Smallest Palindromic Rearrangement I
// Difficulty: Medium
// Tags: String, Sorting, Counting Sort
// Status: Accepted
// Language: cpp
// Runtime: 38
// Memory: 75776000
// URL: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
//
// Question:
// You are given a palindromic string s.
// Return the lexicographically smallest palindromic permutation of s.
// Example 1:
// Input:s = "z"
// Output:"z"
// Explanation:
// A string of only one character is already the lexicographically smallest palindrome.
// Example 2:
// Input:s = "babab"
// Output:"abbba"
// Explanation:
// Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.
// Example 3:
// Input:s = "daccad"
// Output:"acddca"
// Explanation:
// Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.
// Constraints:
// - 1 <= s.length <= 10^5
// - s consists of lowercase English letters.
// - s is guaranteed to be palindromic.
//
// Example Testcases:
// "z"
// "babab"
// "daccad"

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        string left_half = "";
        string mid = "";

        for (int i = 0; i < 26; i++) {
            if (count[i] == 0) continue;
            if (count[i] % 2 != 0) {
                mid = (char)('a' + i);
            }
            left_half.append(count[i] / 2, (char)('a' + i));
        }
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        return left_half + mid + right_half;
    }
};
