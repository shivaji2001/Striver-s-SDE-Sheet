// R
// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) 
    {
        int n=dist.size();
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][via]!=100000000 and dist[via][j]!=100000000 and i!=j)
                       dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        
        
    }
};