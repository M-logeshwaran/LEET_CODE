// LeetCode 125. Valid Palindrome
// Difficulty: Easy
// Tags: Two Pointers, String
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 10324000
// URL: https://leetcode.com/problems/valid-palindrome/
//
// Question:
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.
// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
// Constraints:
// - 1 <= s.length <= 2 * 10^5
// - s consists only of printable ASCII characters.
//
// Example Testcases:
// "A man, a plan, a canal: Panama"
// "race a car"
// " "

class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        string result = "";
        while(i<s.size()){
            if((int)s[i] >= 65 && (int)s[i] <= 90){
                result.push_back((char)((int)s[i] + 32));
                i++;
            }
            else if(((int)s[i] >= 97 && (int)s[i] <= 122) || ((int)s[i] >= 48 && (int)s[i] <= 57)){
                result.push_back(s[i]);
                i++;
            }
            else{
                i++;
            }
        }
        int j=result.size()-1;
        i = 0;
        while(i<=j){
            if(result[i] != result[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
