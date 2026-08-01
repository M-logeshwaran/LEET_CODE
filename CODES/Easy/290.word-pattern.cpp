// LeetCode 290. Word Pattern
// Difficulty: Easy
// Tags: Hash Table, String
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 8720000
// URL: https://leetcode.com/problems/word-pattern/
//
// Question:
// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
// - Each letter in pattern maps to exactly one unique word in s.
// - Each unique word in s maps to exactly one letter in pattern.
// - No two letters map to the same word, and no two words map to the same letter.
// Example 1:
// Input:pattern = "abba", s = "dog cat cat dog"
// Output:true
// Explanation:
// The bijection can be established as:
// - 'a' maps to "dog".
// - 'b' maps to "cat".
// Example 2:
// Input:pattern = "abba", s = "dog cat cat fish"
// Output:false
// Example 3:
// Input:pattern = "aaaa", s = "dog cat cat dog"
// Output:false
// Constraints:
// - 1 <= pattern.length <= 300
// - pattern contains only lower-case English letters.
// - 1 <= s.length <= 3000
// - s contains only lowercase English letters and spaces ' '.
// - sdoes not contain any leading or trailing spaces.
// - All the words in s are separated by a single space.
//
// Example Testcases:
// "abba"
// "dog cat cat dog"
// "abba"
// "dog cat cat fish"
// "aaaa"
// "dog cat cat dog"

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        string s1 = "";
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == ' '){
                str.push_back(s1);
                s1 = "";
            }
            else{
                s1 += s[i];
            }
        }
        str.push_back(s1);
        int size1 = pattern.size();
        int size2 = str.size();
        if(size1 != size2){
            return false;
        }
        unordered_map<char, string> map;
        unordered_map<string, char> map2;
        for(int i=0 ; i<pattern.size() ; i++ ){
            if(map.contains(pattern[i]) || map2.contains(str[i])){
                if(map[pattern[i]] == str[i] && map2[str[i]] == pattern[i]){
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                map[pattern[i]] = str[i];
                map2[str[i]] = pattern[i];
            }
        }
        return true;
    }
};
