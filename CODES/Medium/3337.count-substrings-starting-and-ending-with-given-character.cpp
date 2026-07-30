// LeetCode 3337. Count Substrings Starting and Ending with Given Character
// Difficulty: Medium
// Tags: Math, String, Counting
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 13228000
// URL: https://leetcode.com/problems/count-substrings-starting-and-ending-with-given-character/
//
// Question:
// You are given a string s and a character c. Return the total number of substrings of s that start and end with c.
// Example 1:
// Input: s = "abada", c = "a"
// Output: 6
// Explanation: Substrings starting and ending with "a" are: "abada", "abada", "abada", "abada", "abada", "abada".
// Example 2:
// Input: s = "zzz", c = "z"
// Output: 6
// Explanation: There are a total of 6 substrings in s and all start and end with "z".
// Constraints:
// - 1 <= s.length <= 10^5
// - s and c consist only of lowercase English letters.
//
// Example Testcases:
// "abada"
// "a"
// "zzz"
// "z"

class Solution {
public:
    long long countSubstrings(string s, char c) {
        int count = 0;
        long long int sum = 0;
        for(char i : s){
            if(i == c){
                count++;
                sum += count;
            }
        }
        return sum;
    }
};
