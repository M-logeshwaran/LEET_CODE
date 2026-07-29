// LeetCode 33. Search in Rotated Sorted Array
// Difficulty: Medium
// Tags: Array, Binary Search
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 15264000
// URL: https://leetcode.com/problems/search-in-rotated-sorted-array/
//
// Question:
// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
// Given the array numsafter the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
// You must write an algorithm with O(log n) runtime complexity.
// Example 1:
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:
// Input: nums = [1], target = 0
// Output: -1
// Constraints:
// - 1 <= nums.length <= 5000
// - -10^4 <= nums[i] <= 10^4
// - All values of nums are unique.
// - nums is an ascending array that is possibly rotated.
// - -10^4 <= target <= 10^4
//
// Example Testcases:
// [4,5,6,7,0,1,2]
// 0
// [4,5,6,7,0,1,2]
// 3
// [1]
// 0

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int le = 0;
        int ri = nums.size()-1;
        while(le <= ri){
            int mid = (le + (ri-le)/2);
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] >= nums[le]){
                if(nums[le] <= target && nums[mid] > target){
                    ri = mid-1;
                }
                else{
                    le = mid+1;
                }
            }
            else{
                if(nums[ri] >= target && nums[mid] < target){
                    le = mid+1;
                }
                else{
                    ri = mid-1;
                }
            }
        }
        return -1;
    }
};
