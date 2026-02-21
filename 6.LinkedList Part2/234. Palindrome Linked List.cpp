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
    ListNode* reverse(ListNode* head)
    {
        
        ListNode* prev=NULL;
        while(head!=NULL)
        {
           ListNode* temp=head->next;
           head->next=prev;
           prev=head;
           head=temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) 
    {
        if(head->next==NULL) return true;
        
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=NULL and fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;

        }
        prev->next=NULL;
        ListNode* revLL=reverse(slow);
        while(temp!=NULL and revLL!=NULL)
        {
            if(temp->val!=revLL->val) return false;
            temp=temp->next;
            revLL=revLL->next;

        }
        return true;
    }
};