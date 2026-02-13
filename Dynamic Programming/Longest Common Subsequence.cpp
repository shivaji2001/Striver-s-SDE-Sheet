// https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
class Solution {
  public:
    int helper(string &s1, string &s2,int n,int m,vector<vector<int>>&dp)
    {
        if(n==0 or m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m]=1+helper(s1, s2,n-1,m-1,dp);
        }
        return dp[n][m]=max( helper(s1, s2,n-1,m,dp),helper(s1, s2,n,m-1,dp)  );
    }
    int lcs(string &s1, string &s2) 
    {
       int n=s1.size();
       int m=s2.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       return helper(s1, s2,n, m,dp); 
    }
};