
// R
// https://www.geeksforgeeks.org/problems/bipartite-graph/1
class Solution {
  public:
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
                
                queue<pair<int,int>>q;
                q.push({i,-1});
                visited[i]=true;
                color[i]=0;
                while(!q.empty())
                {
                    pair<int,int>p=q.front();
                    q.pop();
                    int x=p.first;
                    int parent=p.second;
                    for(int a:adj[x])
                    {
                        if(visited[a]==false)
                        {
                            q.push({a,x});
                            visited[a]=true;
                            color[a]=color[x]==0?1:0;
                        }
                        else if(color[a]==color[x])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
        
        
       
        
    }
};