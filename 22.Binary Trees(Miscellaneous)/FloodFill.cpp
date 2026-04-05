// https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    bool canVisit(int x,int y, int n ,int m)
    {
        if(x>=0 and x<n and y>=0 and y<m)
        return true;

        return false;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int oc=image[sr][sc];
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=true;
        vector<pair<int,int>>dirn={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            image[p.first][p.second]=color;
            
            for(auto it:dirn)
            {
                int nx=p.first+it.first;
                int ny=p.second+it.second;
                
                if(canVisit(nx,ny,n , m) and visited[nx][ny]==false   and image[nx][ny]==oc)
                {
                    
                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }

        }
        return image;
    }
};