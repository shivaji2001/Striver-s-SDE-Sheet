class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n=grid.size();
        vector<int>check(n*n,1);
        int repeated=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int no=abs(grid[i][j]);
                
                int x=(no-1)/n;
                int y=(no-1)%n;
                if(grid[x][y]<0)
                {
                     repeated=no;
                }
                else
                {
                    grid[x][y]=-grid[x][y];
                }
                
            }
        }
        int missing=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0)
                {
                    missing=i*n+j+1;
                }
            }
        }
        return {repeated,missing};

        

    }
};