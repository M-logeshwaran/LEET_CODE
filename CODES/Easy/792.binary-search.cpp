// LeetCode 792. Binary Search
// Difficulty: Easy
// Tags: Array, Binary Search
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 31448000
// URL: https://leetcode.com/problems/binary-search/
//
// Question:
// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.
// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
// Constraints:
// - 1 <= nums.length <= 10^4
// - -10^4 < nums[i], target < 10^4
// - All the integers in nums are unique.
// - nums is sorted in ascending order.
//
// Example Testcases:
// [-1,0,3,5,9,12]
// 9
// [-1,0,3,5,9,12]
// 2

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int le = 0;
        int ri = nums.size()-1;
        vector<int> result = {-1,-1};
        while(le<=ri){
            int mid = le+(ri-le)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                ri = mid-1;
            }
            else{
                le = mid+1;
            }
        }
        return -1;
    }
};
