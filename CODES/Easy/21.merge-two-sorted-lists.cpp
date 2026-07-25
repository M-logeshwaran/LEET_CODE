// LeetCode 21. Merge Two Sorted Lists
// Difficulty: Easy
// Tags: Linked List, Recursion
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 19640000
// URL: https://leetcode.com/problems/merge-two-sorted-lists/
//
// Question:
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.
// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:
// Input: list1 = [], list2 = []
// Output: []
// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]
// Constraints:
// - The number of nodes in both lists is in the range [0, 50].
// - -100 <= Node.val <= 100
// - Both list1 and list2 are sorted in non-decreasing order.
//
// Example Testcases:
// [1,2,4]
// [1,3,4]
// []
// []
// []
// [0]

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * head1 = new ListNode(0);
        ListNode * point = head1;
        while(list1 != nullptr || list2 != nullptr){
            if(list1 != nullptr && (list2 == nullptr || list1->val <= list2->val)){
                ListNode * c_n  = new ListNode(list1->val);
                point->next = c_n;
                list1 = list1->next;
            }
            else{
                ListNode * c_n  = new ListNode(list2->val);
                point->next = c_n;
                list2 = list2->next;
            }
            point = point->next;
        }
        ListNode * head = head1->next;
        delete head1;
        return head;     
    }
};
