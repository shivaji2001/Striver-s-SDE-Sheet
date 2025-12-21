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
        if(head==NULL) return false;
        if(head->next==NULL) return false;
        if(head->next==head) return true;

        ListNode* slow=head;
        ListNode* fast=head;
        int hasRun=false;
        while(fast!=NULL  and fast->next!=NULL and (slow!=fast || hasRun==false ))
        {
            hasRun=true;
            slow=slow->next;
            fast=fast->next->next;

        }
        if(slow==fast)
        {
            return true;
        }
        return false;
    }
};