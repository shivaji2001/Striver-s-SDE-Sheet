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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        ListNode* head=NULL;
        ListNode* ans=NULL;
        while(list1!=NULL and list2!=NULL)
        {
            if(list1->val<list2->val)
            {
               if(head==NULL)
               {
                head=list1;
                ans=list1;
                list1=list1->next;
                head->next=NULL;
               }
               else
               {
                head->next=list1;
                head=head->next;
                list1=list1->next;
               }
            }
            else
            {
                if(head==NULL)
               {
                head=list2;
                ans=list2;
                list2=list2->next;
                head->next=NULL;
               }
               else
               {
                head->next=list2;
                head=head->next;
                list2=list2->next;
               }
            }
        }
        if(list1==NULL)
        {
            head->next=list2;
        }
        else if(list2==NULL)
        {
            head->next=list1;
        }
        return ans;
        
    }
};