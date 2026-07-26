// LeetCode 628. Maximum Product of Three Numbers
// Difficulty: Easy
// Tags: Array, Math, Sorting
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 31332000
// URL: https://leetcode.com/problems/maximum-product-of-three-numbers/
//
// Question:
// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
// Example 1:
// Input: nums = [1,2,3]
// Output: 6
// Example 2:
// Input: nums = [1,2,3,4]
// Output: 24
// Example 3:
// Input: nums = [-1,-2,-3]
// Output: -6
// Constraints:
// - 3 <= nums.length <= 10^4
// - -1000 <= nums[i] <= 1000
//
// Example Testcases:
// [1,2,3]
// [1,2,3,4]
// [-1,-2,-3]

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN , max2 = INT_MIN , max3 = INT_MIN;
        int min1 = INT_MAX , min2 = INT_MAX;
        for (int i : nums){
            if(i > max1){
                max3 = max2;
                max2 = max1;
                max1 = i;
            }
            else if(i > max2){
                max3 = max2;
                max2 = i;
            }
            else if(i > max3){
                max3 = i;
            }

            if(i < min1){
                min2 = min1;
                min1 = i;
            }
            else if(i < min2){
                min2 = i;
            }
        }
        return max(max1*max2*max3 , min1*min2*max1);
    }    
};
