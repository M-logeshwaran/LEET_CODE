// LeetCode 34. Find First and Last Position of Element in Sorted Array
// Difficulty: Medium
// Tags: Array, Binary Search
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 17620000
// URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
//
// Question:
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.
// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]
// Constraints:
// - 0 <= nums.length <= 10^5
// - -10^9 <= nums[i] <= 10^9
// - nums is a non-decreasing array.
// - -10^9 <= target <= 10^9
//
// Example Testcases:
// [5,7,7,8,8,10]
// 8
// [5,7,7,8,8,10]
// 6
// []
// 0

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int le = 0;
        int ri = nums.size()-1;
        vector<int> result = {-1,-1};
        while(le<=ri){
            int mid = le+(ri-le)/2;
            if(nums[mid] == target){
                result[0] = mid;
                ri = mid-1;
            }
            else if(nums[mid] > target){
                ri = mid-1;
            }
            else{
                le = mid+1;
            }
        }
        le = 0, ri = nums.size()-1;
        while(le<=ri){
            int mid = le+(ri-le)/2;
            if(nums[mid] == target){
                result[1] = mid;
                le = mid+1;
            }
            else if(nums[mid] > target){
                ri = mid-1;
            }
            else{
                le = mid+1;
            }
        }
        return result;
    }
};
