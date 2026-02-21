// R:-Priority_queue method
// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
class Solution {
  public:
    // O(N^2) approach
    // int minIndexFinder(vector<int>&dist,vector<bool>&relaxed)
    // {
    //     int n=dist.size();
    //     int mini=INT_MAX;
    //     int index=-1;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(dist[i]<mini and relaxed[i]==false)
    //         {
    //             mini=dist[i];
    //             index=i;
    //         }
    //     }
    //     return index;
    // }
    // vector<int> dijkstra(int v, vector<vector<int>> &edges, int src) 
    // {
    //     vector<vector<pair<int,int>>>adj(v);
    //     for(auto x:edges)
    //     {
    //         int a=x[0];
    //         int b=x[1];
    //         int dist=x[2];
    //         adj[a].push_back({b,dist});
    //         adj[b].push_back({a,dist});
    //     }
    //     vector<int>dist(v,INT_MAX);
    //     vector<bool>relaxed(v,false);
    //     dist[src]=0;
    //     for(int i=0;i<v-1;i++)
    //     {
    //         int miniIndex=minIndexFinder(dist,relaxed);
    //         relaxed[miniIndex]=true;
    //         for(auto a:adj[miniIndex])
    //         {
    //             dist[a.first]=min(dist[a.first],dist[miniIndex]+a.second);
    //         }
    //     }
    //     return dist;
        
        
    // }
    
    vector<int> dijkstra(int v, vector<vector<int>> &edges, int src) 
    {
        vector<vector<pair<int,int>>>adj(v);
        for(auto x:edges)
        {
            int a=x[0];
            int b=x[1];
            int dist=x[2];
            adj[a].push_back({b,dist});
            adj[b].push_back({a,dist});
        }
        vector<int>dist(v,INT_MAX);
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int distance=it.first;
            int node=it.second;
           
            for(auto ad:adj[node])
            {
                if(dist[ad.first]>dist[node]+ad.second)
                {
                   dist[ad.first]=dist[node]+ad.second ;
                   pq.push({dist[ad.first],ad.first});
                }
            }
        }
        return dist;
        
        
    }
};