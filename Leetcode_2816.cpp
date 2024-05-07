/*
2816. Double a Number Represented as a Linked List
Solved
Medium
Topics
Companies
Hint
You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

 

Example 1:


Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.
Example 2:


Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.
*/
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }return prev;
    }
    ListNode* doubleIt(ListNode* head) {
    head = reverseList(head); // Update head to point to the new head of the reversed list
    ListNode* temp = head;
    bool carry = false;
    while (temp != nullptr) {
        temp->val = temp->val * 2 + (carry ? 1 : 0);
        carry = temp->val >= 10;
        temp->val %= 10;
        if (temp->next == nullptr && carry) {
            temp->next = new ListNode(1);
            break;
        }
        temp = temp->next; // Move to the next node
    }
    head = reverseList(head); // Reverse the list back to its original order
    return head;
    }


};