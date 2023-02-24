/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    

    bool hasCycle(ListNode *head) {
        ListNode *fast = head ;
        ListNode *slow = head ;
        while(fast != NULL && fast -> next != NULL)
        {
        // Slow pointer will move by a Single Node everytime

        slow = slow -> next ;

        // Fast Pointer will move with a speed twice to that of Slow Pointer

        fast = fast -> next -> next ;

        // If there's a Cycle in the LinkedList, then Fast and Slow pointer will eventually meet

        if(fast == slow)
            return true ;
    }

    // If we come out of the While Loop, it implies there's no Cycle present in the LinkedList, so we return false

    return false ;
}
    
        
    
};