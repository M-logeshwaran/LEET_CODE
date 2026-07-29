// LeetCode 1894. Merge Strings Alternately
// Difficulty: Easy
// Tags: Two Pointers, String
// Status: Accepted
// Language: cpp
// Runtime: 2
// Memory: 8824000
// URL: https://leetcode.com/problems/merge-strings-alternately/
//
// Question:
// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
// Return the merged string.
// Example 1:
// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1: a b c
// word2: p q r
// merged: a p b q c r
// Example 2:
// Input: word1 = "ab", word2 = "pqrs"
// Output: "apbqrs"
// Explanation: Notice that as word2 is longer, "rs" is appended to the end.
// word1: a b
// word2: p q r s
// merged: a p b q r s
// Example 3:
// Input: word1 = "abcd", word2 = "pq"
// Output: "apbqcd"
// Explanation: Notice that as word1 is longer, "cd" is appended to the end.
// word1: a b c d
// word2: p q
// merged: a p b q c d
// Constraints:
// - 1 <= word1.length, word2.length <= 100
// - word1 and word2 consist of lowercase English letters.
//
// Example Testcases:
// "abc"
// "pqr"
// "ab"
// "pqrs"
// "abcd"
// "pq"

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int n = word1.size(),m = word2.size();
        int i=0,j=0;
        s.reserve(n+m);
        while(i < n && j < m){
                s.push_back(word1[i]);
                s.push_back(word2[j]);
                j++;
                i++;
        }
        while(i<n){
            s.push_back(word1[i]);
            i++;
        }
        while(j<m){
            s.push_back(word2[j]);
            j++;
        }        
        return s;
    }
};
