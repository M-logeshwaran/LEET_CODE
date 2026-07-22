// LeetCode 9. Palindrome Number
// Difficulty: Easy
// Tags: Math
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 8640000
// URL: https://leetcode.com/problems/palindrome-number/
//
// Question:
// Given an integer x, return true if x is a palindrome, and false otherwise.
// Example 1:
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
// Constraints:
// - -2^31 <= x <= 2^31 - 1
// Follow up: Could you solve it without converting the integer to a string?
//
// Example Testcases:
// 121
// -121
// 10

class Solution {
public:
    bool isPalindrome(int x) {
        int c_x = x;
        long int r_x = 0;
        if(x<0){
            return false;
        }
        else{
            while(c_x>0){
                r_x = r_x*10;
                r_x = r_x + (c_x%10);
                c_x = c_x/10;
            }
            if(r_x == x){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
