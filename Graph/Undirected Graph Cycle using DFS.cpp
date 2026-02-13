// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    bool helper(int src,int parent,vector<vector<int>>&adj,vector<int>&visited)
    {
        for(int a:adj[src])
        {
            if(visited[a]==false and a!=parent)
            {
                visited[a]=true;
                bool x=helper(a, src,adj,visited);
                if(x==true) return true;
            }
            else if(visited[a]==true and a!=parent)
            {
                return true;
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
        // cout<<"Printing adj"<<endl;
        // for(int i=0;i<adj.size();i++)
        // {
        //     for(int a:adj[i])
        //     {
        //         cout<<a<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        
        // bool tempo=helper(0, -1,adj,visited);
        // cout<<"value is "<<tempo<<endl;
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                bool xyz=helper(i, -1,adj,visited);
                //cout<<"i and xyz are:- "<<i<<" "<<xyz<<endl;
                if(xyz==true) return true;
            }
             
        }
        return false;
        
    }
};