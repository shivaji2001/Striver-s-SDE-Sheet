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
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        if(k==0) return head;
        ListNode* temp=head;
        while(head!=NULL)
        {
            n++;
            head=head->next;
        }
        if(n==k) return temp;
        k=k%n;
        if(k==0)
        {
            return temp;
        }
        head=temp;
        int c=n-k-1;
        
        while(c--)
        {
            head=head->next;
        }
        ListNode* newHead=head->next;
        head->next=NULL;
        ListNode* ans=newHead;
        while(newHead->next!=NULL)
        {
            newHead=newHead->next;
        }
        newHead->next=temp;
        return ans;
    }
};