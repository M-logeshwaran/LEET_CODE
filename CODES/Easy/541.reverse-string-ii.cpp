// LeetCode 541. Reverse String II
// Difficulty: Easy
// Tags: Two Pointers, String
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 9456000
// URL: https://leetcode.com/problems/reverse-string-ii/
//
// Question:
// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.
// Example 1:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"
// Example 2:
// Input: s = "abcd", k = 2
// Output: "bacd"
// Constraints:
// - 1 <= s.length <= 10^4
// - s consists of only lowercase English letters.
// - 1 <= k <= 10^4
//
// Example Testcases:
// "abcdefg"
// 2
// "abcd"
// 2

class Solution {
public:
    string reverseStr(string s, int k) {
        if(k>s.size()){
            k = s.size();
        }
        int sub = 2*k;
        int i = 0;
        int j = k-1;
        while(i < s.size()){
            int i1 = i;
            int j1 = j;
            while(i1<j1){
                char temp = s[i1];
                s[i1] = s[j1];
                s[j1] = temp;
                i1++;
                j1--;
            }
            i = i+(sub);
            if((i + k - 1) >= s.size()){ 
                j = s.size() - 1; 
            } 
            else{ 
                j = i + k - 1; 
            }  
        }    
        return s;
    }
};
