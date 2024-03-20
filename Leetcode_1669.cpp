/*
1669. Merge In Between Linked Lists
Solved
Medium
Topics
Companies
Hint
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:


Build the result list and return its head.

 

Example 1:


Input: list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
Output: [10,1,13,1000000,1000001,1000002,5]
Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
Example 2:
*/
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1;
        ListNode* temp2 = nullptr;
        ListNode* temp3 = nullptr;
        
        int count = 0;
        while (temp) {
            if (count == a - 1) {
                temp2 = temp;
            }
            if (count == b) {
                temp3 = temp->next;
                break;
            }
            temp = temp->next;
            count++;
        }
        
        temp2->next = list2;
        while (list2->next) {
            list2 = list2->next;
        }
        list2->next = temp3;
        
        return list1;
    }
};
