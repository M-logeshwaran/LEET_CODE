// LeetCode 58. Length of Last Word
// Difficulty: Easy
// Tags: String
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 8856000
// URL: https://leetcode.com/problems/length-of-last-word/
//
// Question:
// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.
// Example 1:
// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:
// Input: s = " fly me to the moon "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:
// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.
// Constraints:
// - 1 <= s.length <= 10^4
// - s consists of only English letters and spaces ' '.
// - There will be at least one word in s.
//
// Example Testcases:
// "Hello World"
// "   fly me   to   the moon  "
// "luffy is still joyboy"

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int c=0;
        for(int i=s.size()-1 ; i>=0 ; i--){
            if(s[i] == ' '){
                if(c == 1){
                    break;
                }
                continue;
            }
            else{
                c=1;
                length++;
            }
        }
        return length;
    }
};
