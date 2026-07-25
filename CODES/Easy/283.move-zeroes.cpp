// LeetCode 283. Move Zeroes
// Difficulty: Easy
// Tags: Array, Two Pointers
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 23840000
// URL: https://leetcode.com/problems/move-zeroes/
//
// Question:
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.
// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:
// Input: nums = [0]
// Output: [0]
// Constraints:
// - 1 <= nums.length <= 10^4
// - -2^31 <= nums[i] <= 2^31 - 1
// Follow up: Could you minimize the total number of operations done?
//
// Example Testcases:
// [0,1,0,3,12]
// [0]

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        for(int j=0; j<nums.size() ; j++){
            if(nums[i] == 0 && nums[j]!=0){
                nums[i] = nums[j];
                nums[j] = 0;
            }
            if(nums[i] == 0){
                continue;
            }
            else{
                i++;
            }
        }
    }
};
