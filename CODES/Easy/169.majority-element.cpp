// LeetCode 169. Majority Element
// Difficulty: Easy
// Tags: Array, Hash Table, Divide and Conquer, Sorting, Counting
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 28288000
// URL: https://leetcode.com/problems/majority-element/
//
// Question:
// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Example 1:
// Input: nums = [3,2,3]
// Output: 3
// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
// Constraints:
// - n == nums.length
// - 1 <= n <= 5 * 10^4
// - -10^9 <= nums[i] <= 10^9
// - The input is generated such that a majority element will exist in the array.
// Follow-up: Could you solve the problem in linear time and in O(1) space?
//
// Example Testcases:
// [3,2,3]
// [2,2,1,1,1,2,2]

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(count == 0 ){
                ans=nums[i];
                count=1;
            }
            else if (ans==nums[i]){
                count++;
                
            }
            else {
                count--;
            }
            }
        
        return ans;
    }
};
