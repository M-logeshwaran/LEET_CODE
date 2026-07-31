// LeetCode 908. Middle of the Linked List
// Difficulty: Easy
// Tags: Linked List, Two Pointers
// Status: Accepted
// Language: cpp
// Runtime: N/A
// Memory: 9872000
// URL: https://leetcode.com/problems/middle-of-the-linked-list/
//
// Question:
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.
// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: The middle node of the list is node 3.
// Example 2:
// Input: head = [1,2,3,4,5,6]
// Output: [4,5,6]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
// Constraints:
// - The number of nodes in the list is in the range [1, 100].
// - 1 <= Node.val <= 100
//
// Example Testcases:
// [1,2,3,4,5]
// [1,2,3,4,5,6]

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
    ListNode* middleNode(ListNode* head) {
        ListNode * fast = head;
        ListNode * slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
