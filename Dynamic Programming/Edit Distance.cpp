// R
// https://www.geeksforgeeks.org/problems/edit-distance3702/1
class Solution {
  public:
    int helper(string& s1, string& s2,int n,int m,vector<vector<int>>&dp)
    {
        if(n==0 and m==0) return 0;
        if(n==0 and m!=0) return m;
        if(n!=0 and m==0) return n;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1]) return dp[n][m]=helper(s1,s2,n-1,m-1,dp);
        
        int ins=1+helper(s1,s2,n,m-1,dp);
        int rem=1+helper(s1,s2,n-1,m,dp);
        int repl=1+helper(s1,s2,n-1,m-1,dp);
        return dp[n][m]=min(ins,min(rem,repl));
    }
    int editDistance(string& s1, string& s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return helper(s1,s2,n,m,dp);
        
    }
};