// LeetCode 412. Fizz Buzz
// Difficulty: Easy
// Tags: Math, String, Simulation
// Status: Accepted
// Language: cpp
// Runtime: 3
// Memory: 11704000
// URL: https://leetcode.com/problems/fizz-buzz/
//
// Question:
// Given an integer n, return a string array answer (1-indexed) where:
// - answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
// - answer[i] == "Fizz" if i is divisible by 3.
// - answer[i] == "Buzz" if i is divisible by 5.
// - answer[i] == i (as a string) if none of the above conditions are true.
// Example 1:
// Input: n = 3
// Output: ["1","2","Fizz"]
// Example 2:
// Input: n = 5
// Output: ["1","2","Fizz","4","Buzz"]
// Example 3:
// Input: n = 15
// Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
// Constraints:
// - 1 <= n <= 10^4
//
// Example Testcases:
// 3
// 5
// 15

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> str;
        if(n == 0){
            return str;
        }
        for(int i=1 ; i<=n ; i++){
            if(i%3 == 0 && i%5 == 0){
                str.push_back("FizzBuzz");
            }
            else if(i%3 == 0){
                str.push_back("Fizz");
            }
            else if(i%5 == 0){
                str.push_back("Buzz");
            }
            else{
                str.push_back(to_string(i));
            }
        }
        return str;
    }
};
