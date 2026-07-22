// LeetCode 231. Power of Two
// Difficulty: Easy
// Tags: Math, Bit Manipulation, Recursion
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 7792000
// URL: https://leetcode.com/problems/power-of-two/
//
// Question:
// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2^x.
// Example 1:
// Input: n = 1
// Output: true
// Explanation: 2^0 = 1
// Example 2:
// Input: n = 16
// Output: true
// Explanation: 2^4 = 16
// Example 3:
// Input: n = 3
// Output: false
// Constraints:
// - -2^31 <= n <= 2^31 - 1
// Follow up: Could you solve it without loops/recursion?
//
// Example Testcases:
// 1
// 16
// 3

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0 && ((n & (n-1)) == 0)){
            return true;
        }
        else{
            return false;
        }
    }
};
