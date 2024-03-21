/*
206. Reverse Linked List
Solved
Easy
Topics
Companies
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:
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
        ListNode* temp=head;
        ListNode* c1;
        ListNode* c2=NULL;
        ListNode* curr=head;
        while(temp!=NULL){
            c1=temp->next;
            temp->next=c2;
            c2=temp;
            temp=c1;
            
        }
        return c2;
    }
};