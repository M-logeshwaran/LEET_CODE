// LeetCode 35. Search Insert Position
// Difficulty: Easy
// Tags: Array, Binary Search
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 13716000
// URL: https://leetcode.com/problems/search-insert-position/
//
// Question:
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.
// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4
// Constraints:
// - 1 <= nums.length <= 10^4
// - -10^4 <= nums[i] <= 10^4
// - nums contains distinct values sorted in ascending order.
// - -10^4 <= target <= 10^4
//
// Example Testcases:
// [1,3,5,6]
// 5
// [1,3,5,6]
// 2
// [1,3,5,6]
// 7

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int mid;
        int left = 0,right = nums.size()-1;
        while(left <= right){
            mid = left + (right - left)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};
