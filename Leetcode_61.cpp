/*
61. Rotate List
Solved
Medium
Topics
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109*/

// my code 
class Solution {
public:
    ListNode* rotate(ListNode* head){
        if (head == nullptr || head->next == nullptr) return head; // Handle edge cases

        ListNode *temp = head;
        int c = temp->val;

        while (temp->next != nullptr) {
            int st = temp->next->val;
            temp->next->val = c;
            c = st;
            temp = temp->next;
        }
        head->val = c;
        return head;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; // Handle edge cases

        // Calculate the length of the list
        ListNode* temp = head;
        int s = 0;
        while (temp != nullptr) {
            temp = temp->next;
            s++;
        }
        if (s == 0) return head; // Edge case when the list is empty

        k = k % s;
        if (k == 0) return head; // No rotation needed

        while (k > 0) {
            head = rotate(head);
            k--;
        }
        return head;
    }
};


//optimized code 

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};