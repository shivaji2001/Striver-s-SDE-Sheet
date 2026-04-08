// https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {
public:
    string longestPalindrome(string str) 
    {
        int n=str.size();
      vector<vector<bool>>dp(n,vector<bool>(n,false));
      for(int i=0;i<n;i++)
      dp[i][i]=true;
       
      int x=0;
      int y=0;
      int len=1;
      for(int i=1;i<n;i++)
      {
          for(int j=0;j<n-i;j++)
          {
              int start=j;
              int end=start+i;
              if(end-start==1 and str[end]==str[start])
              {
                  if(end-start+1>len)
                  {
                      x=start;
                      y=end;
                  }
                  dp[start][end]=1;
              }
              else if(end-start>1 and dp[start+1][end-1]==true and str[start]==str[end])
              {
                  if(end-start+1>len)
                  {
                      x=start;
                      y=end;
                  }
                  dp[start][end]=true;
              }
          }

      }

      string ans=str.substr(x,y-x+1);
      return ans;
    }

};