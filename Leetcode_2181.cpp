/*
2181. Merge Nodes in Between Zeros
Solved
Medium
Topics
Companies
Hint
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

 

Example 1:


Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> s;
        bool f = true;
        ListNode* temp = head;
        int a = 0;
        temp = temp->next; // skip the initial zero node
        while (temp != NULL) {
            if (temp->val != 0) {
                a += temp->val;
            } else {
                s.push_back(a);
                a = 0; // reset the accumulator
            }
            temp = temp->next;
        }

        // Create the new list from the accumulated sums
        ListNode* newHead = new ListNode(0); // dummy node
        ListNode* current = newHead;
        for (int val : s) {
            current->next = new ListNode(val);
            current = current->next;
        }

        return newHead->next; // skip the dummy node
    }
};
