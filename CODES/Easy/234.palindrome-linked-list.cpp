// LeetCode 234. Palindrome Linked List
// Difficulty: Easy
// Tags: Linked List, Two Pointers, Stack, Recursion
// Status: Accepted
// Language: cpp
// Runtime: 1
// Memory: 127212000
// URL: https://leetcode.com/problems/palindrome-linked-list/
//
// Question:
// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// Example 1:
// Input: head = [1,2,2,1]
// Output: true
// Example 2:
// Input: head = [1,2]
// Output: false
// Constraints:
// - The number of nodes in the list is in the range [1, 10^5].
// - 0 <= Node.val <= 9
// Follow up: Could you do it in O(n) time and O(1) space?
//
// Example Testcases:
// [1,2,2,1]
// [1,2]

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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return true;
        }
        vector<int> stk;
        int top = -1;
        ListNode * head1 = head;
        while((head1 != nullptr && head1->next != nullptr)){
            stk.push_back(head->val);
            top++;
            head = head->next;
            head1 = head1->next->next;
        }
        if(head1 != nullptr){
            head = head->next;
        }
        while(head != nullptr){
            if(stk[top] == head->val){
                stk.pop_back();
                top--;
            }
            head = head->next;
        }
        return stk.empty();
    }
};
