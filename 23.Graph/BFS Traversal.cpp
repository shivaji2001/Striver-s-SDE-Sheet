// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) 
    {
        int n=adj.size();
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        vector<int>ans;
        visited[0]=true;
        while(!q.empty())
        {
            int x=q.front();
            ans.push_back(x);
            q.pop();
            for(int a:adj[x])
            {
                if(visited[a]==false)
                {
                    visited[a]=true;
                    q.push(a);
                }
            }
        }
        return ans;
      
        
    }
};