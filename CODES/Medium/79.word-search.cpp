// LeetCode 79. Word Search
// Difficulty: Medium
// Tags: Array, String, Backtracking, Depth-First Search, Matrix
// Status: Accepted
// Language: cpp
// Runtime: 811
// Memory: 11528000
// URL: https://leetcode.com/problems/word-search/
//
// Question:
// Given an m x n grid of characters board and a string word, return trueifwordexists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
// Constraints:
// - m == board.length
// - n = board[i].length
// - 1 <= m, n <= 6
// - 1 <= word.length <= 15
// - board and word consists of only lowercase and uppercase English letters.
// Follow up: Could you use search pruning to make your solution faster with a larger board?
//
// Example Testcases:
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// "ABCCED"
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// "SEE"
// [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// "ABCB"


bool find(vector<vector<char>>& board , string word , int column , int row , int str_pos){
    if(column < 0 || column >= board[0].size() || row < 0 || row >= board.size() || board[row][column] == '#'){
        return false;
    }
    if(board[row][column] != word[str_pos]){
        return false;
    }
    if(board[row][column] == word[str_pos] && (str_pos + 1) == word.size()){
        return true;
    }
    char temp = board[row][column];
    board[row][column] = '#';
    bool up = find(board , word , column , row-1 , str_pos+1);
    bool down = find(board , word , column , row+1 , str_pos+1);
    bool right = find(board , word , column+1 , row , str_pos+1);
    bool left = find(board , word , column-1 , row , str_pos+1);
    board[row][column] = temp;
    return (up || down || right || left);
}

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size() ; i++){
            for(int j=0 ; j<board[0].size() ; j++){
                if(find(board,word,j,i,0)){
                    return true;
                }
            }           
        }
        return false;
    }    
};
