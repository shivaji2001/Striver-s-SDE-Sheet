// https://www.geeksforgeeks.org/problems/coin-change2448/1
class Solution {
  public:
    int helper(int ind,int coinRequired,vector<int>& coins,vector<vector<int>>&dp)
    {
        int n=coins.size();
        if(ind>=n)
        {
            if(coinRequired==0) return 1;
            return 0;
        }
        if(coinRequired<=0)
        {
            if(coinRequired==0) return 1;
            return 0 ;
        }
        if(dp[ind][coinRequired]!=-1) return dp[ind][coinRequired];
        int sum=0;
        for(int i=ind;i<n;i++)
        {
            int x=helper(i,coinRequired-coins[i],coins,dp);
            sum+=x;
        }
        return dp[ind][coinRequired]=sum;
    }
    int count(vector<int>& coins, int sum) {
      int ans=0;
      int n=coins.size();
      vector<vector<int>>dp(n,vector<int>(sum+1,-1));
      return helper(0,sum,coins,dp);
    
    }
};