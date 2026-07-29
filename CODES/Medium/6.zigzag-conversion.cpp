// LeetCode 6. Zigzag Conversion
// Difficulty: Medium
// Tags: String
// Status: Accepted
// Language: cpp
// Runtime: 6
// Memory: 14400000
// URL: https://leetcode.com/problems/zigzag-conversion/
//
// Question:
// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
// P A H N
// A P L S I I G
// Y I R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:
//
// string convert(string s, int numRows);
// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P I N
// A L S I G
// Y A H R
// P I
// Example 3:
// Input: s = "A", numRows = 1
// Output: "A"
// Constraints:
// - 1 <= s.length <= 1000
// - s consists of English letters (lower-case and upper-case), ',' and '.'.
// - 1 <= numRows <= 1000
//
// Example Testcases:
// "PAYPALISHIRING"
// 3
// "PAYPALISHIRING"
// 4
// "A"
// 1

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || s.size() <= numRows) {
            return s;
        }
        vector<string> result(numRows,"");
        int i=0;
        int index = 0;
        string result1 = "";
        while(index<s.size()){
            while(i<numRows && index<s.size()){
                result[i] += s[index];
                i++;
                index++;
            }
            i -= 2;
            while(i>=0 && index<s.size()){
                result[i] += s[index];
                i--;
                index++;
            }
            i += 2;
        }
        for(string j : result){
            result1 += j;
        }
        return result1;
    }
};
