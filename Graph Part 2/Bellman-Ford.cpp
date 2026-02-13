// R
// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// User function Template for C++

class Solution {
  public:
    bool hasNegativeCycle(vector<vector<int>>& edges,vector<int>&dist)
    {
        for(int j=0;j<edges.size();j++)
            {
                int a=edges[j][0];
                int b=edges[j][1];
                int di=edges[j][2];
                if(dist[a]!=100000000)
                {
                    if(dist[b]>dist[a]+di)
                    {
                        return true;
                    }
                }
                  
            }
            return false;
    }
    vector<int> bellmanFord(int v, vector<vector<int>>& edges, int src) {
        vector<int>dist(v,100000000);
        dist[src]=0;
        for(int i=0;i<v-1;i++)
        {
            for(int j=0;j<edges.size();j++)
            {
                int a=edges[j][0];
                int b=edges[j][1];
                int di=edges[j][2];
                if(dist[a]!=100000000)
                  dist[b]=min(dist[b],dist[a]+di);
            }
            
        }
        if( hasNegativeCycle(edges,dist))
        {
            return {-1};
        }
       
        return dist;
        
    }
};