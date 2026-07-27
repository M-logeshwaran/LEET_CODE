// LeetCode 61. Rotate List
// Difficulty: Medium
// Tags: Linked List, Two Pointers
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 16296000
// URL: https://leetcode.com/problems/rotate-list/
//
// Question:
// Given the head of a linked list, rotate the list to the right by k places.
// Example 1:
// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:
// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
// Constraints:
// - The number of nodes in the list is in the range [0, 500].
// - -100 <= Node.val <= 100
// - 0 <= k <= 2 * 10^9
//
// Example Testcases:
// [1,2,3,4,5]
// 2
// [0,1,2]
// 4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        int length = 1;
        ListNode * point_end = head;
        while(point_end->next != nullptr){
            point_end = point_end->next;
            length++;
        }
        k = k%length;
        point_end->next = head;
        ListNode* new_end = head;
        for(int i=1; i<(length-k) ; i++){
            new_end = new_end->next;
        }
        head = new_end->next;
        new_end->next = nullptr;
        return head;
    }
};
