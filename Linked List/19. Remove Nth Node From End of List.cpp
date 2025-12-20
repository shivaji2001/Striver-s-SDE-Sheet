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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(head!=NULL)
        {
            count++;
            head=head->next;
        }
        head=temp;
        if(count==1) return NULL;
        if(count==2 and n==2) return head->next;
        if(count==2 and n==1)
        {
            head->next=NULL;
            return head;
        }
       
        int moves=count-n-1;
        if(moves==-1) return head->next;
        while( moves--)
        {
            head=head->next;
        }
        if(head->next->next==NULL)
        {
            head->next=NULL;
        }
        else
        {
            head->next=head->next->next;
        }
        return temp;
    }
};