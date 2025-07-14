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
    int getDecimalValue(ListNode* head) {
        ListNode* temp =head;
        int a=0;
        int ans=0;
        while(temp->next!=NULL){
            temp=temp->next;
            a++;
        }
        temp=head;
        cout<<a;
        //a--;
        while(temp->next!=NULL){
            ans+=(temp->val * (pow(2,a)));
            a--;
            temp=temp->next;
        }
        ans+=(temp->val * (pow(2,a)));
        return ans;
    }
};