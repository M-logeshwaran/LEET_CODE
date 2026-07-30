// LeetCode 442. Find All Duplicates in an Array
// Difficulty: Medium
// Tags: Array, Hash Table, Sorting
// Status: Accepted
// Language: cpp
// Runtime: 61
// Memory: 67272000
// URL: https://leetcode.com/problems/find-all-duplicates-in-an-array/
//
// Question:
// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at mosttwice, return an array of all the integers that appears twice.
// You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output
// Example 1:
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:
// Input: nums = [1,1,2]
// Output: [1]
// Example 3:
// Input: nums = [1]
// Output: []
// Constraints:
// - n == nums.length
// - 1 <= n <= 10^5
// - 1 <= nums[i] <= n
// - Each element in nums appears once or twice.
//
// Example Testcases:
// [4,3,2,7,8,2,3,1]
// [1,1,2]
// [1]

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> map;
        vector<int> result;
        for(int i=0 ; i<nums.size() ; i++){
            if(map.contains(nums[i])){
                map[nums[i]] += 1;
            }
            else{
                map[nums[i]] = 1;
            }
        }
        for(const auto& [key, value] : map){
            if(value == 2){
                result.push_back(key);
            }
        }
        return result;
    }
};
