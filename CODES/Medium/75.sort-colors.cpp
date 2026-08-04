// LeetCode 75. Sort Colors
// Difficulty: Medium
// Tags: Array, Two Pointers, Sorting, Quicksort, Bubble Sort
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 11520000
// URL: https://leetcode.com/problems/sort-colors/
//
// Question:
// Given an array nums with n objects colored red, white, or blue, sort them in-placeso that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.
// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]
// Constraints:
// - n == nums.length
// - 1 <= n <= 300
// - nums[i] is either 0, 1, or 2.
// Follow up: Could you come up with a one-pass algorithm using only constant extra space?
//
// Example Testcases:
// [2,0,2,1,1,0]
// [2,0,1]

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> map(3,0);
        for(int i:nums){
            map[i] += 1; 
        }
        int j=0;
        int i=0;
        while(i<nums.size()){
            if(map[j] != 0){
                nums[i] = j;
                map[j] -= 1;
                i++;
            }
            else{
                j++;
            }
        }
    }
};
