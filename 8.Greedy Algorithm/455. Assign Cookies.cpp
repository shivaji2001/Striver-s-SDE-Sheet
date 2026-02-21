// https://leetcode.com/problems/assign-cookies/description/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(),g.end(),greater<int>());
        priority_queue<int,vector<int>>pq;
        for(int a:s)
        {
            pq.push(a);
        }
        int n=g.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(pq.size()>0 and g[i]<=pq.top())
            {
                ans++;
                pq.pop();
            }
        }
        return ans;
        
    }
};