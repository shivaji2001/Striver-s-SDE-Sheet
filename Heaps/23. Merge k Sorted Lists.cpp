// https://leetcode.com/problems/merge-k-sorted-lists/description/
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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {   
        ListNode* temp=NULL;
        ListNode* ans=NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        int n=lists.size();
        for(int i=0;i<n;i++)
        {
            if(lists[i]!=NULL)
            pq.push({ lists[i]->val,lists[i] });
        }
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            if(temp==NULL)
            {
                temp=new ListNode(x.first);
                ans=temp;
            }
            else
            {
                temp->next=new ListNode(x.first);
                temp=temp->next;
            }
            ListNode* tp=x.second;
            tp=tp->next;
            if(tp!=NULL)
            {
                pq.push({tp->val,tp});
            }
        }
        return ans;
    }
};