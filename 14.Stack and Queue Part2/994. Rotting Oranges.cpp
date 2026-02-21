// R
// https://leetcode.com/problems/rotting-oranges/description/
class Solution {
public:
   
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int,int>>dirn={{-1,0},{1,0},{0,-1},{0,1}};

        int zeros=0;
        int ones=0;
        int twos=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                     zeros++;
                     visited[i][j]=true;
                }
                else if(grid[i][j]==1)
                {
                     ones++;
                }
                else
                {
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        

        int time=0;
        while(!q.empty())
        {
            if(ones==0) return time;
            int sz=q.size();
            time++;
            while(sz--)
            {
                pair<int,int>p=q.front();
                int x=p.first;
                int y=p.second;
                
                q.pop();
                for(auto dir:dirn)
                {
                    
                    int nx=x+dir.first;
                    int ny=y+dir.second;
                    
                   
                    if(nx>=0 and nx<n and ny>=0 and ny<m and visited[nx][ny]==false )
                    {
                        
                        visited[nx][ny]=true;
                        ones--;
                        
                        q.push({nx,ny});
                    }
                }
            }
           
            
        }
        if(ones==0) return time;
        else return -1;

        
    }
};