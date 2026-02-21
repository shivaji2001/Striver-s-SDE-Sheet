// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// User function Template for C++

class Solution {
  public:
    int helper(int len,vector<int> &price,int n, vector<int>&dp)
    {
        if(len==0) return 0;
        int maxi=INT_MIN;
        if(dp[len]!=-1) return dp[len];
        for(int k=1 ;k<=len;k++)
        {
           int pr=price[k-1]+helper(len-k,price,n,dp);
           maxi=max(maxi,pr);
        }
        return dp[len]=maxi;
    }
    int cutRod(vector<int> &price) 
    {
        int n=price.size();
        vector<int>dp(n+1,-1);
        return helper(n,price,n,dp);
    }
};