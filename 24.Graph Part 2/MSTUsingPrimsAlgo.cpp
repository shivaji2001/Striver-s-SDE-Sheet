// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(V);
        vector<vector<int>>wts(V,vector<int>(V,0));
        for(int i=0;i<edges.size();i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            int wt=edges[i][2];
            adj[x].push_back(y);
            adj[y].push_back(x);
            wts[x][y]=wt;
            wts[y][x]=wt;
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>visited(V,false);
        pq.push({0,0});
        int ans=0;
        while(!pq.empty())
        {
            pair<int,int>p=pq.top();
            pq.pop();
            int wt=p.first;
            int node=p.second;
            if(visited[node]==true)
            {
                continue;
            }
            ans+=wt;
            visited[node]=true;
            for(int a:adj[node])
            {
                pq.push({wts[node][a],a});
            }
        }
        return ans;
        
        
    }
};