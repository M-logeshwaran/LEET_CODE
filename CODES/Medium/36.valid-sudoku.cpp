// LeetCode 36. Valid Sudoku
// Difficulty: Medium
// Tags: Array, Hash Table, Matrix
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 22796000
// URL: https://leetcode.com/problems/valid-sudoku/
//
// Question:
// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// - Each row must contain the digits 1-9 without repetition.
// - Each column must contain the digits 1-9 without repetition.
// - Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:
// - A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// - Only the filled cells need to be validated according to the mentioned rules.
// Example 1:
// Input: board =
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:
// Input: board =
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
// Constraints:
// - board.length == 9
// - board[i].length == 9
// - board[i][j] is a digit 1-9 or '.'.
//
// Example Testcases:
// [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// [["8","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<int> arr(10,0);
        for(int row = 0 ; row<board.size() ; row++){
            for(int column = 0 ; column<board[0].size() ; column++){
                if(board[row][column] == '.'){
                    continue;
                }
                if(((int)board[row][column] > 48 && (int)board[row][column] <= 57 ) && (arr[(int)board[row][column] - (int)'0'] == 0)){
                    arr[(int)board[row][column] - (int)'0'] += 1;
                }
                else{
                    return false;
                }
            }
            arr.assign(10, 0);
        }

        for(int column = 0 ; column<board.size() ; column++){
            for(int row = 0 ; row<board[0].size() ; row++){
                if(board[row][column] == '.'){
                    continue;
                }
                if(((int)board[row][column] > 48 && (int)board[row][column] <= 57 ) && (arr[(int)board[row][column] - (int)'0'] == 0)){
                    arr[(int)board[row][column] - (int)'0'] += 1;
                }
                else{
                    return false;
                }
            }
            arr.assign(10, 0);
        }
        int n1 = 0;
        int n2 = 3;
        int m1 = 0;
        int m2 = 3;

        for(int block = 0; block < 9; block++){
            for(int row = n1; row < n2; row++){
                for(int column = m1; column < m2; column++){
                    if(board[row][column] == '.'){
                        continue;
                    }
                    if(((int)board[row][column] > 48 && (int)board[row][column] <= 57 ) && (arr[(int)board[row][column] - (int)'0'] == 0)){
                        arr[(int)board[row][column] - (int)'0'] += 1;
                    }
                    else{
                        return false;
                    }
                }
            }
            arr.assign(10, 0);
            if((block + 1) % 3 != 0){
                m1 = m2;
                m2 += 3;
            }
            else{
                m1 = 0;
                m2 = 3;
                n1 = n2;
                n2 += 3;
            }
        }
        return true;

    }
};
