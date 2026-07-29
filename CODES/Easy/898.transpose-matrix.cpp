// LeetCode 898. Transpose Matrix
// Difficulty: Easy
// Tags: Array, Matrix, Simulation
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 15060000
// URL: https://leetcode.com/problems/transpose-matrix/
//
// Question:
// Given a 2D integer array matrix, return the transpose ofmatrix.
// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]
// Example 2:
// Input: matrix = [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]
// Constraints:
// - m == matrix.length
// - n == matrix[i].length
// - 1 <= m, n <= 1000
// - 1 <= m * n <= 10^5
// - -10^9 <= matrix[i][j] <= 10^9
//
// Example Testcases:
// [[1,2,3],[4,5,6],[7,8,9]]
// [[1,2,3],[4,5,6]]

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> matrix1(matrix[0].size(),vector<int>(matrix.size()));
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                matrix1[j][i] = matrix[i][j];
            }
        }
        return matrix1;
    }
};
