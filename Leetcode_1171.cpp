/*
1171. Remove Zero Sum Consecutive Nodes from Linked List
Medium
Topics
Companies
Hint
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        int sum = 0;
        unordered_map<int, ListNode*> m;

        while (temp != nullptr) {
            sum += temp->val;

            if (m.find(sum) != m.end()) {
                // Remove nodes from m[sum]->next to current
                ListNode* start = m[sum]->next;
                int tempSum = sum;
                while (start != temp) {
                    tempSum += start->val;
                    m.erase(tempSum);
                    start = start->next;
                }

                // Adjust pointers
                m[sum]->next = temp->next;
            } else {
                m[sum] = temp;
            }

            temp = temp->next;
        }

        return dummy->next;
    }
};
