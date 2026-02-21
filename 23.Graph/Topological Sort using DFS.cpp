// R
//  https://www.geeksforgeeks.org/problems/topological-sort/1
class Solution {
  public:
    
    void dfs(int src,vector<bool>&visited,vector<int>&ans,vector<vector<int>>&adj)
    {
        for(int a:adj[src])
        {
            if(visited[a]==false)
            {
                visited[a]=true;
                dfs(a,visited,ans,adj);
            }
        }
        ans.push_back(src);
    }
    vector<int> topoSort(int v, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(v);
        
        for(auto a:edges)
        {
            adj[a[0]].push_back(a[1]);
            
        }
        vector<int>ans;
        vector<bool>visited(v,false);
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                dfs(i,visited,ans,adj);
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
       
        
    }
};