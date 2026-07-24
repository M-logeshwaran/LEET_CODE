// LeetCode 1. Two Sum
// Difficulty: Easy
// Tags: Array, Hash Table
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 15876000
// URL: https://leetcode.com/problems/two-sum/
//
// Question:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]
// Constraints:
// - 2 <= nums.length <= 10^4
// - -10^9 <= nums[i] <= 10^9
// - -10^9 <= target <= 10^9
// - Only one valid answer exists.
// Follow-up: Can you come up with an algorithm that is less than O(n^2)time complexity?
//
// Example Testcases:
// [2,7,11,15]
// 9
// [3,2,4]
// 6
// [3,3]
// 6

#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans = {0,0};
        unordered_map<int, int> mp;
        int c_d;
        for(int i=0 ; i<nums.size() ; i++){
            c_d = target - nums[i];
            if(mp.find(c_d) != mp.end()){
                ans[0] = mp[c_d];
                ans[1] = i;
            }
            else{
                mp[nums[i]] = i;
            }
        }
        return ans;
    }

};
