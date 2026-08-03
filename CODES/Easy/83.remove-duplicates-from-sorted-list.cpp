// LeetCode 83. Remove Duplicates from Sorted List
// Difficulty: Easy
// Tags: Linked List
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 16248000
// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
//
// Question:
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]
// Example 2:
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]
// Constraints:
// - The number of nodes in the list is in the range [0, 300].
// - -100 <= Node.val <= 100
// - The list is guaranteed to be sorted in ascending order.
//
// Example Testcases:
// [1,1,2]
// [1,1,2,3,3]

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode * point1 = head;
        ListNode * point2 = head->next;
        while(point2 != nullptr){
            if(point1->val != point2->val){
                point1->next->val = point2->val;
                point1 = point1->next;
                point2 = point2->next;
            }
            else{
                point2 = point2->next;
            }
        }
        point1->next = nullptr;
        return head;
    }
};
