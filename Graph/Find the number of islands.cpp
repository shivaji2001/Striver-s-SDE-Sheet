
// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
class Solution {
  public:
    void bfs(int x,int y,vector<vector<bool>>&visited,int n,int m,vector<pair<int,int>>&dirn,vector<vector<char>>& grid)
    {
        queue<pair<int,int>>q;
        q.push({x,y});
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            int xc=p.first;
            int yc=p.second;
            for(auto dir:dirn)
            {
                int nxc=xc+dir.first;
                int nyc=yc+dir.second;
                if(nxc>=0 and nxc<n and nyc>=0 and nyc<m and visited[nxc][nyc]==false and grid[nxc][nyc]=='L')
                {
                    visited[nxc][nyc]=true;
                    q.push({nxc,nyc});
                }
            }
        }
    }
    int countIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<pair<int,int>>dirn={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==false and grid[i][j]=='L')
                {
                    ans++;
                    visited[i][j]=true;
                    bfs(i,j,visited,n,m,dirn,grid);
                }
            }
        }
        return ans;
        
    }
};