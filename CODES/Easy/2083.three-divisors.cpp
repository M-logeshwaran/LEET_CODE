// LeetCode 2083. Three Divisors
// Difficulty: Easy
// Tags: Math, Enumeration, Number Theory
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 7828000
// URL: https://leetcode.com/problems/three-divisors/
//
// Question:
// Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.
// An integer m is a divisor of n if there exists an integer k such that n = k * m.
// Example 1:
// Input: n = 2
// Output: false
// Explantion: 2 has only two divisors: 1 and 2.
// Example 2:
// Input: n = 4
// Output: true
// Explantion: 4 has three divisors: 1, 2, and 4.
// Constraints:
// - 1 <= n <= 10^4
//
// Example Testcases:
// 2
// 4

class Solution {
public:
    bool isThree(int n) {
        if(n==1 || n==2){
            return false;
        }
        if(n%2 == 0){
            int c = 0;
            for(int i=3 ; i<n ; i++){
                if(n%i == 0){
                    c = 1;
                }
            }
            return ((c == 0) ? true : false);
        }
        else{
            int c = 0;
            for(int i=2 ; i<n ; i++){
                if(n%i == 0){
                    c += 1;
                }
            }
            return ((c == 1) ? true : false);
        }
    }
};
