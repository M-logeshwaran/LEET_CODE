// LeetCode 1168. Duplicate Zeros
// Difficulty: Easy
// Tags: Array, Two Pointers
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 14484000
// URL: https://leetcode.com/problems/duplicate-zeros/
//
// Question:
// Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
// Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
// Example 1:
// Input: arr = [1,0,2,3,0,4,5,0]
// Output: [1,0,0,2,3,0,0,4]
// Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
// Example 2:
// Input: arr = [1,2,3]
// Output: [1,2,3]
// Explanation: After calling your function, the input array is modified to: [1,2,3]
// Constraints:
// - 1 <= arr.length <= 10^4
// - 0 <= arr[i] <= 9
//
// Example Testcases:
// [1,0,2,3,0,4,5,0]
// [1,2,3]

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int j = 0;
        int i = 0;
        if(arr.size() == 1){
            return;
        }
        vector<int> stack1;
        while((j) != arr.size()){
            if(stack1.size() != 0){
                stack1.push_back(arr[j]);
                arr[j] = stack1[i];
                i++;
            }
            if(arr[j] == 0 && (j+1) < arr.size()){
                stack1.push_back(arr[j+1]);
                arr[j+1] = 0;
                j=j+2;
            }
            else{
                j++;
            }
        }
    }
};
