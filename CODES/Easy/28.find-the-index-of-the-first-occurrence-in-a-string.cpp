// LeetCode 28. Find the Index of the First Occurrence in a String
// Difficulty: Easy
// Tags: Two Pointers, String, String Matching, Z Algorithm, Knuth–Morris–Pratt Algorithm, Boyer–Moore String-Search Algorithm
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 9020000
// URL: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
//
// Question:
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
// Example 1:
// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:
// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.
// Constraints:
// - 1 <= haystack.length, needle.length <= 10^4
// - haystack and needle consist of only lowercase English characters.
//
// Example Testcases:
// "sadbutsad"
// "sad"
// "leetcode"
// "leeto"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();
        if( size1 < size2 ){
            return -1;
        }
        char ch = needle[0];
        int j;
        for(int i=0 ; i<=size1 - size2 ; i++){
            j = 1;
            if(haystack[i] == ch){
                while(j<needle.size()){
                    if(haystack[i+j] == needle[j]){
                        j++;
                        continue;
                    }
                    else{
                        break;
                    }
                }
                if(j == needle.size()){
                    return i;
                }
            }
        }
        return -1;
    }
};
