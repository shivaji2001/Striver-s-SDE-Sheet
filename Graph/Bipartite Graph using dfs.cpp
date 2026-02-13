// R
//  https://www.geeksforgeeks.org/problems/bipartite-graph/1
class Solution {
  public:
    bool dfs(int src,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&color)
    {   
        
        for(int a:adj[src])
        {
            if(visited[a]==false)
            {
                visited[a]=true;
                color[a]=color[src]==0?1:0;
                bool check=dfs( a,adj,visited,color);
                if(check==false) return false;
                
            }
            else if(color[a]==color[src])
            {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(int v, vector<vector<int>> &edges) 
    {
        vector<vector<int>>adj(v);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>visited(v,false);
        vector<bool>color(v,-1);
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                color[i]=0;
                bool a=dfs(i,adj,visited,color);
                
                if(a==false) return false;
            }
        }
        return true;
        
        
       
        
    }
};