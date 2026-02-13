// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    bool helper(int src,int v, vector<vector<int>>& edges,vector<vector<int>>&adj,vector<int>&visited)
    {
        queue<pair<int,int>>q;
        q.push({src,-1});
        visited[src]=true;
        while(!q.empty())
        {
            pair<int,int>x=q.front();
            q.pop();
            for(int a:adj[x.first])
            {
                if(visited[a]==false)
                {
                    q.push({a,x.first});
                    visited[a]=true;
                }
                else if( visited[a]==true and a!=x.second)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int v, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(v);
        vector<int>visited(v,false);
        for(auto a:edges)
        {
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
               if(helper(i,v, edges,adj,visited)) return true;
        }
        return false;
        
    }
};