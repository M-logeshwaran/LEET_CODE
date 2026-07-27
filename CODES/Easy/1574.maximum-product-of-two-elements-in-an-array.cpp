// LeetCode 1574. Maximum Product of Two Elements in an Array
// Difficulty: Easy
// Tags: Array, Sorting, Heap (Priority Queue)
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 13532000
// URL: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
//
// Question:
// Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of(nums[i]-1)*(nums[j]-1).
// Example 1:
// Input: nums = [3,4,5,2]
// Output: 12
// Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12.
// Example 2:
// Input: nums = [1,5,4,5]
// Output: 16
// Explanation: Choosing the indices i=1 and j=3 (indexed from 0), you will get the maximum value of (5-1)*(5-1) = 16.
// Example 3:
// Input: nums = [3,7]
// Output: 12
// Constraints:
// - 2 <= nums.length <= 500
// - 1 <= nums[i] <= 10^3
//
// Example Testcases:
// [3,4,5,2]
// [1,5,4,5]
// [3,7]

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 2){
            return (nums[0]-1)*(nums[1]-1);
        }
        int max1 = INT_MIN , max2 = INT_MIN;
        int pos1 = -1 , pos2 = -1;
        for ( int i= 0 ; i<nums.size() ; i++){
            if(nums[i] >= max1){
                max2 = max1;
                pos2 = pos1;
                max1 = nums[i];
                pos1 = i;
            }
            else if(nums[i] > max2){
                max2 = nums[i];
                pos2 = i;
            }
        }
        return (nums[pos2]-1)*(nums[pos1]-1);
    }
};
