// LeetCode 206. Reverse Linked List
// Difficulty: Easy
// Tags: Linked List, Recursion
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 13600000
// URL: https://leetcode.com/problems/reverse-linked-list/
//
// Question:
// Given the head of a singly linked list, reverse the list, and return the reversed list.
// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:
// Input: head = [1,2]
// Output: [2,1]
// Example 3:
// Input: head = []
// Output: []
// Constraints:
// - The number of nodes in the list is the range [0, 5000].
// - -5000 <= Node.val <= 5000
// Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
//
// Example Testcases:
// [1,2,3,4,5]
// [1,2]
// []

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

ListNode* reve(ListNode * node){
        if(node->next == nullptr){
            return node;
        }
        else{
            ListNode * node2 = reve(node->next);
            node->next->next = node;
            node->next = nullptr;
            return node2; 
        }
 }

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        return reve(head);
    }
};
