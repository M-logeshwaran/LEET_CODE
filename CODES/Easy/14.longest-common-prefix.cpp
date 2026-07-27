// LeetCode 14. Longest Common Prefix
// Difficulty: Easy
// Tags: Array, String, Trie
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 12008000
// URL: https://leetcode.com/problems/longest-common-prefix/
//
// Question:
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
// Constraints:
// - 1 <= strs.length <= 200
// - 0 <= strs[i].length <= 200
// - strs[i] consists of only lowercase English letters if it is non-empty.
//
// Example Testcases:
// ["flower","flow","flight"]
// ["dog","racecar","car"]

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1){
            return strs[0];
        }
        string s = strs[0];
        int index_till = s.size();
        for(int i=1 ; i<strs.size() ; i++){
            int temp = 0;
            for(int j=0 ; j<index_till ; j++){
                if(strs[i].size() > j && s[j] == strs[i][j]){
                    temp += 1 ;
                }
                else{
                    break;
                }
            }
            index_till = temp;
        }
        string result = "";
        for(int i=0 ; i<index_till ; i++){
            result = result + s[i];
        }
        return result;
    }
};
