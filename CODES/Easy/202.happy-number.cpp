// LeetCode 202. Happy Number
// Difficulty: Easy
// Tags: Hash Table, Math, Two Pointers
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 7892000
// URL: https://leetcode.com/problems/happy-number/
//
// Question:
// Write an algorithm to determine if a number n is happy.
// A happy number is a number defined by the following process:
// - Starting with any positive integer, replace the number by the sum of the squares of its digits.
// - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// - Those numbers for which this process ends in 1 are happy.
// Return trueifnis a happy number, andfalseif not.
// Example 1:
// Input: n = 19
// Output: true
// Explanation:
// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1
// Example 2:
// Input: n = 2
// Output: false
// Constraints:
// - 1 <= n <= 2^31 - 1
//
// Example Testcases:
// 19
// 2

class Solution {
public:
    bool isHappy(int n) {
        int value;
        while(n!=1 && n!=4){
            value = 0;
            while(n>0){
                value += (n%10)*(n%10);
                n = n/10;   
            }
            n = value;
        }
        return (n==1);
    }
};
