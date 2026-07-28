// LeetCode 2491. Smallest Even Multiple
// Difficulty: Easy
// Tags: Math, Number Theory
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 7788000
// URL: https://leetcode.com/problems/smallest-even-multiple/
//
// Question:
// Given a positive integer n, return the smallest positive integer that is a multiple of both2 and n.
// Example 1:
// Input: n = 5
// Output: 10
// Explanation: The smallest multiple of both 5 and 2 is 10.
// Example 2:
// Input: n = 6
// Output: 6
// Explanation: The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.
// Constraints:
// - 1 <= n <= 150
//
// Example Testcases:
// 5
// 6

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n == 2 || n == 1){
            return 2;
        }
        return ((n%2 != 0) ? n*2 : n);
    }
};
