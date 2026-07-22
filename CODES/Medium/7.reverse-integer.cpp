// LeetCode 7. Reverse Integer
// Difficulty: Medium
// Tags: Math
// Status: Accepted
// Language: cpp
// Runtime: 2
// Memory: 8644000
// URL: https://leetcode.com/problems/reverse-integer/
//
// Question:
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
// Example 1:
// Input: x = 123
// Output: 321
// Example 2:
// Input: x = -123
// Output: -321
// Example 3:
// Input: x = 120
// Output: 21
// Constraints:
// - -2^31 <= x <= 2^31 - 1
//
// Example Testcases:
// 123
// -123
// 120

class Solution {
public:
    int reverse(int x) {
        long int r_x = 0;
        while(x!=0){
            r_x = r_x * 10;
            r_x = r_x + (x%10);
            x = x/10;
        }
        if(r_x > INT_MAX || r_x < INT_MIN){
            return 0;
        }
        return (int)r_x;
    }
};
