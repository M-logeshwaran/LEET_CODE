// LeetCode 1128. Remove All Adjacent Duplicates In String
// Difficulty: Easy
// Tags: String, Stack
// Status: Accepted
// Language: cpp
// Runtime: 4
// Memory: 13656000
// URL: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
//
// Question:
// You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
// We repeatedly make duplicate removals on s until we no longer can.
// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
// Example 1:
// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move. The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".
// Example 2:
// Input: s = "azxxzy"
// Output: "ay"
// Constraints:
// - 1 <= s.length <= 10^5
// - s consists of lowercase English letters.
//
// Example Testcases:
// "abbaca"
// "azxxzy"

class Solution {
public:
    string removeDuplicates(string s) {
        if(s.size() == 1){
            return s;
        }
        string result = "";
        int top = 0;
        result.push_back(s[0]);
        for(int i=1 ; i<s.size() ; i++){
            if(!result.empty() && s[i] == result[top]){
                result.pop_back();
                top--;
            }
            else{
                result.push_back(s[i]);
                top++;
            }
        }
        return result;

        // Brute force

        /*int i=0;
        int j=1;
        int action = 0;
        while(j <= s.size())
        {
            if(i == (s.size()-1) || s[i] != s[j]){
                result += s[i];
                i++;
                j++;
            }
            else{
                action = 1;
                i = j+1;
                j = j+2;
            }
            if(j>=s.size() && i>=s.size())
            {
                if(action == 0){
                    return result;
                }
                else{
                    action = 0;
                }
                s = result;
                result = "";
                i=0;
                j=1;
         
            }
        }
        return result;*/
    }
};
