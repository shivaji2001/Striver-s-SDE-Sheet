// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  public:
    void helper(int src,vector<vector<int>>& adj,vector<int>&ans,vector<bool>&visited)
    {
        visited[src]=true;
        ans.push_back(src);
        for(int a:adj[src])
        {
            if(visited[a]==false)
              helper(a,adj,ans,visited);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>ans;
        
        vector<bool>visited(n,false);
        helper(0,adj,ans,visited);
        return ans;
        
    }
};