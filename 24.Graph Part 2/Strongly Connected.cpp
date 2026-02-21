// R
// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
class Solution {
  public:
    void dfs(int src,vector<vector<int>> &adj,stack<int>&st,vector<bool>&visited)
    {
        for(int a:adj[src])
        {
            if(visited[a]==false)
            {
                visited[a]=true;
                dfs(a,adj,st,visited);
            }
        }
        st.push(src);
    }
    void dfs2(int src,vector<vector<int>> &adj2,vector<bool>&vis2)
    {
         for(int a:adj2[src])
        {
            if(vis2[a]==false)
            {
                vis2[a]=true;
                dfs2(a,adj2,vis2);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj)
    {
        int v=adj.size();
        vector<bool>visited(v,false);
        stack<int>st;
        
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                dfs(i,adj,st,visited);
            }
        }
        
        vector<vector<int>>adj2(v);
        for(int i=0;i<v;i++)
        {
            for(int x:adj[i])
            {
                adj2[x].push_back(i);
            }
        }
        vector<bool>vis2(v,false);
        int ans=0;
        while(!st.empty())
        {
            int a=st.top();
            st.pop();
            if(vis2[a]==false)
            {
                ans++;
                vis2[a]=true;
                dfs2(a,adj2,vis2);
                
            }
        }
        return ans;
        
       
    }
};