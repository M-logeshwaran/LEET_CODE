// LeetCode 49. Group Anagrams
// Difficulty: Medium
// Tags: Array, Hash Table, String, Sorting
// Status: Accepted
// Language: cpp
// Runtime: 1107
// Memory: 23336000
// URL: https://leetcode.com/problems/group-anagrams/
//
// Question:
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// Example 1:
// Input:strs = ["eat","tea","tan","ate","nat","bat"]
// Output:[["bat"],["nat","tan"],["ate","eat","tea"]]
// Explanation:
// - There is no string in strs that can be rearranged to form "bat".
// - The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// - The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:
// Input:strs = [""]
// Output:[[""]]
// Example 3:
// Input:strs = ["a"]
// Output:[["a"]]
// Constraints:
// - 1 <= strs.length <= 10^4
// - 0 <= strs[i].length <= 100
// - strs[i] consists of lowercase English letters.
//
// Example Testcases:
// ["eat","tea","tan","ate","nat","bat"]
// [""]
// ["a"]


bool anagram(const string& s, const string& t) {
        if(s.size() != t.size()){
            return false;
        }
        int array[26] = {0};

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

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size1 = strs.size();
        if(size1 == 0 || size1 == 1){
            return {strs};
        }
        vector<int> track(size1,0);
        vector<vector<string>> result;
        for(int i=0 ; i<size1 ; i++){
            if(track[i] == 1){
                continue;
            }
            vector<string> str;
            str.push_back(strs[i]);
            for(int j=i+1 ; j<size1 ; j++){
                if(track[j] == 1){
                    continue;
                }
                if(anagram(strs[i] , strs[j])){
                    track[j] = 1;
                    str.push_back(strs[j]);
                }
            }
            result.push_back(str);
        }
        return result;
    }
};
