// LeetCode 242. Valid Anagram
// Difficulty: Easy
// Tags: Hash Table, String, Sorting
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 9760000
// URL: https://leetcode.com/problems/valid-anagram/
//
// Question:
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// Example 1:
// Input:s = "anagram", t = "nagaram"
// Output:true
// Example 2:
// Input:s = "rat", t = "car"
// Output:false
// Constraints:
// - 1 <= s.length, t.length <= 5 * 10^4
// - s and t consist of lowercase English letters.
// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
//
// Example Testcases:
// "anagram"
// "nagaram"
// "rat"
// "car"

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        vector<int> array(26,0);

        for(int i=0 ; i<s.size() ; i++){
            array[(int)s[i] - 97] += 1;
        }
        for(int i=0 ; i<t.size() ; i++){
            array[(int)t[i] - 97] -= 1;
        }

        for(int i : array){
            if(i != 0){
                return false;
            }
        }
        return true;
    }
};
