// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
class Solution {
  public:
    int helper(int i,int j,vector<int> &arr,vector<vector<int>>&dp)
    {
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int x=arr[i-1]*arr[k]*arr[j] + helper(i,k,arr,dp)+helper(k+1,j,arr,dp);
            mini=min(mini,x);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) 
    {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(1,n-1,arr,dp);
    }
};