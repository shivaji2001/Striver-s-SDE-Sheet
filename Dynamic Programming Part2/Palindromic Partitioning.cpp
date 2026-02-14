// https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// User function Template for C++

class Solution {
  public:
    // O(N^3) Approach
    int helper(int i,int j,vector<vector<bool>>&dp,vector<vector<int>>&minimumCut)
    {
        
        if(dp[i][j]==true)
        return minimumCut[i][j]=0;
        if(minimumCut[i][j]!=-1) return minimumCut[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int x=1+helper(i,k,dp,minimumCut)+helper(k+1,j,dp,minimumCut);
            mini=min(mini,x);
            
        }
        return minimumCut[i][j]=mini;
    }
    // O (N^2) approach
    int helper2(int i,string &s,vector<vector<bool>>&dp,int n, vector<int>&minimumCut)
    {
        if(dp[i][n-1]==true) return 0;
        int mini=INT_MAX;
        if(minimumCut[i]!=-1) return minimumCut[i];
        for(int k=i;k<n;k++)
        {
            if(dp[i][k]==true)
            {
                mini=min(mini,1+helper2(k+1,s,dp,n,minimumCut));
            }
        }
        return minimumCut[i]=mini;
    }
    int palPartition(string &s)
    {
       int n=s.size();
       vector<vector<bool>>dp(n,vector<bool>(n,false));
    //   vector<vector<int>>minimumCut(n,vector<int>(n,-1));
       for(int i=0;i<n;i++)
       {
          dp[i][i]=true;
         
       }
       for(int i=0;i<n-1;i++)
       {
           int a=0;
           for(int j=0;j<n-i-1;j++)
           {
               int b=a+i+1;
              if(b-a==1)
              {
                  if(s[a]==s[b])
                  {
                      dp[a][b]=true;
                  }
              }
              else if(dp[a+1][b-1]==true and s[a]==s[b])
              {
                  dp[a][b]=true;
                  dp[b][a]=true;
              }
            a++;
           }
         
       }
       vector<int>minimumCut(n,-1);
       int x=helper2(0,s,dp,n,minimumCut);
       return x;
    }
};