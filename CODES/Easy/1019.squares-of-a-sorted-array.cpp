// LeetCode 1019. Squares of a Sorted Array
// Difficulty: Easy
// Tags: Array, Two Pointers, Sorting
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 32140000
// URL: https://leetcode.com/problems/squares-of-a-sorted-array/
//
// Question:
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
// Constraints:
// - 1 <= nums.length <= 10^4
// - -10^4 <= nums[i] <= 10^4
// - nums is sorted in non-decreasing order.
// Follow up: Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
//
// Example Testcases:
// [-4,-1,0,3,10]
// [-7,-3,2,3,11]

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums[0] >= 0){
            for(int i = 0 ; i<nums.size() ; i++){
                nums[i] *= nums[i];
            }
            return nums;
        }
        vector<int> negative;
        int j = 0;
        int st_index;
        for(int i=0 ; i < nums.size() && nums[i] < 0 ; i++){
            negative.push_back(nums[i]*(-1));
            j++;  
            st_index = i+1;
        }
        j=negative.size()-1;
        for(int i=0 ; i<negative.size()/2 ; i++){
            int temp = negative[i];
            negative[i] = negative[j];
            negative[j] = temp;
            j--;
        }
        vector<int> result;
        j = 0;
        while(j<negative.size() || st_index<nums.size()){
            if((j >= negative.size() && st_index < nums.size())){
                result.push_back(nums[st_index]*nums[st_index]);
                st_index++;
            }
            else if((j < negative.size() && st_index >= nums.size())){
                result.push_back(negative[j]*negative[j]);
                j++;
            }
            else if(nums[st_index] <= negative[j]){
                result.push_back(nums[st_index]*nums[st_index]);
                st_index++;
            }
            else if((nums[st_index] > negative[j])){
                result.push_back(negative[j]*negative[j]);
                j++;
            }
        }
        return result;
    }
};
