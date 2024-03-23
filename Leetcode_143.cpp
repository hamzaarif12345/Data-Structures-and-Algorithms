/*

143. Reorder List
Solved
Medium
Topics
Companies
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.*/


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        
        // Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        slow->next = nullptr; // Break the list into two halves
        
        // Merge the two halves alternately
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;
            first->next = second;
            second->next = nextFirst;
            first = nextFirst;
            second = nextSecond;
        }
    }
};



//Aprroach
/*
Find the middle by moving fast & slow iterators.
Remember right part beginning and cut off left part from the right.
Reverse right list, remember it new beginning.
Iterate left part from beginning and right part merging right list nodes into left list.
*/