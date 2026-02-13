//R
//  https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
class Solution {
  public:
    bool helper(int source,vector<vector<int>>&adj,vector<int>&visited,vector<int>&recursiveStack  )
    {
        recursiveStack[source]=true;
        for(int a:adj[source])
        {
            if(visited[a]==false)
            {  
                visited[a]=true;
                bool x=helper(a,adj,visited,recursiveStack  );
                if(x==true) return true;
            }
            else if(visited[a]==true and recursiveStack[a]==true)
            {
                return true;
            }
        }
        recursiveStack[source]=false;
    }
    bool isCyclic(int v, vector<vector<int>> &edges) 
    {
        vector<vector<int>>adj(v);
        for(auto a:edges)
        {
            adj[a[0]].push_back(a[1]);
        }
        vector<int>visited(v,false);
        vector<int>recursiveStack(v,false);
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
               visited[i]=true;
               bool x=helper(i,adj,visited, recursiveStack );
               if(x==true) return true;
            }
        }
        return false;
    }
};