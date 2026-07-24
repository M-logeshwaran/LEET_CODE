// LeetCode 344. Reverse String
// Difficulty: Easy
// Tags: Two Pointers, String
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 27340000
// URL: https://leetcode.com/problems/reverse-string/
//
// Question:
// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.
// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:
// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
// Constraints:
// - 1 <= s.length <= 10^5
// - s[i] is a printable ascii character.
//
// Example Testcases:
// ["h","e","l","l","o"]
// ["H","a","n","n","a","h"]

class Solution {
public:
    void reverseString(vector<char>& s) {
        int j=s.size()-1;
        for(int i=0 ; i<s.size()/2 ; i++){
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                j--;
        }
    }
};
