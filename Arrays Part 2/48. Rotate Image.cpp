class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //find its transpose
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
        {
            if(i<j)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        }
        //swap fir col with last and second with last second and so on
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                 swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }

    }
};