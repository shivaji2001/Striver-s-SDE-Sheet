// https://leetcode.com/problems/coin-change/description/
class Solution {
public:
    int helper(int amt,vector<int>& coins,int n, vector<int>&dp)
    {
         if(amt==0) return 0;
         int mini=INT_MAX;
         if(dp[amt]!=-1) return dp[amt];
         for(int i=0;i<n;i++)
         {
            if(amt>=coins[i])
            {
                int a=helper(amt-coins[i],coins,n,dp);
                if(a!=INT_MAX)
                {
                    a++;
                }
                mini=min(mini,a);
            }
         }
         return dp[amt]=mini;
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans=helper(amount,coins,n,dp);

        return ans==INT_MAX?-1:ans;
    }
};