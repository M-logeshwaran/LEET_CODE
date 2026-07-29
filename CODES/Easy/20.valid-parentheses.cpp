// LeetCode 20. Valid Parentheses
// Difficulty: Easy
// Tags: String, Stack
// Status: Accepted
// Language: cpp
// Runtime: 3
// Memory: 8688000
// URL: https://leetcode.com/problems/valid-parentheses/
//
// Question:
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// - Open brackets must be closed by the same type of brackets.
// - Open brackets must be closed in the correct order.
// - Every close bracket has a corresponding open bracket of the same type.
// Example 1:
// Input:s = "()"
// Output:true
// Example 2:
// Input:s = "()[]{}"
// Output:true
// Example 3:
// Input:s = "(]"
// Output:false
// Example 4:
// Input:s = "([])"
// Output:true
// Example 5:
// Input:s = "([)]"
// Output:false
// Constraints:
// - 1 <= s.length <= 10^4
// - s consists of parentheses only '()[]{}'.
//
// Example Testcases:
// "()"
// "()[]{}"
// "(]"
// "([])"
// "([)]"

class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0){
            return true;
        }
        string stk = "";
        for(char j : s){
            if(j == '(' || j == '[' || j == '{'){
                stk.push_back(j);
            }
            else{
                if(stk.size() == 0){
                    return false;
                }
                if(j == ')' && stk[stk.size()-1] == '('){
                    stk.pop_back();
                }
                else if(j == ']' && stk[stk.size()-1] == '['){
                    stk.pop_back();
                }
                else if(j == '}' && stk[stk.size()-1] == '{'){
                    stk.pop_back();
                }
                else{
                    return false;
                }
            }   
        }
        return (stk.size() == 0);
    }
};
