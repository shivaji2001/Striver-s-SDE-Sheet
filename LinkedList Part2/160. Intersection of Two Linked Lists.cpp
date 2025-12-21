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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int c1=0;
        int c2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(headA!=NULL)
        {
           c1++;
           headA=headA->next;
        }
        while(headB!=NULL)
        {
           c2++;
           headB=headB->next;
        }
        headA=temp1;
        headB=temp2;
        if(c1>c2)
        {
            int diff=abs(c1-c2);
            while(diff--)
            {
                headA=headA->next;
            }
        }
        else
        {
            int diff=abs(c1-c2);
            while(diff--)
            {
                headB=headB->next;
            }
        }
        while(headA!=NULL and headB!=NULL and headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;

        }
        if(headA==headB and headA!=NULL)
        {
            return headA;
        }
        return NULL;

        
    }
};