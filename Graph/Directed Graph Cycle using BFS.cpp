// R
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
  public:
    vector<int> topoSort(int v, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(v);
        vector<int>indegree(v,0);
        for(auto a:edges)
        {
            adj[a[0]].push_back(a[1]);
            indegree[a[1]]++;
        }
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int x=q.front();
            ans.push_back(x);
            q.pop();
            for(int a:adj[x])
            {
                indegree[a]--;
                if(indegree[a]==0)
                {
                    q.push(a);
                }
            }
            
        }
        return ans;
       
        
    }
    bool isCyclic(int v, vector<vector<int>> &edges) 
    {
        vector<int>topo=topoSort(v, edges) ;
        return topo.size()!=v;
        
        
    }
};