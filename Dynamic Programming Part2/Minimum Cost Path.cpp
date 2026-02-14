
//https://www.geeksforgeeks.org/problems/minimum-cost-path3833/1
class Solution {
  public:
   
     int minimumCostPath(vector<vector<int>>& grid) 
     {
         int n=grid.size();
         queue<pair<int,int>>q;
         q.push({0,0});
         vector<pair<int,int>>dirn={{1,0},{-1,0},{0,1},{0,-1}};
         vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
         dp[0][0]=grid[0][0];
         while(!q.empty())
         {
             pair<int,int>p=q.front();
             q.pop();
             int x=p.first;
             int y=p.second;
             for(auto it:dirn)
             {
                 int nx=x+it.first;
                 int ny=y+it.second;
                 if(nx>=0 and nx<n and ny>=0 and ny<n and dp[nx][ny]>dp[x][y]+grid[nx][ny] )
                 {
                    dp[nx][ny]=dp[x][y]+grid[nx][ny];
                    q.push({nx,ny});
                 }
             }
         }
         return dp[n-1][n-1];
         
     }
};