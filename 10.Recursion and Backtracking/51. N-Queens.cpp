// https://leetcode.com/problems/n-queens/description/

class Solution {
public:
    bool isValid(int x,int y,vector<bool>&rowsOccupied,vector<bool>&colsOccupied,int n,vector<string>&dp)
    {
       if(rowsOccupied[x]) return false;
       if(colsOccupied[y]) return false;
       int tx=x;
       int ty=y;
       while(tx>=0 and ty>=0)
       {
         if(dp[tx][ty]=='Q') return false;
         tx--;
         ty--;
       }
       tx=x;
       ty=y;
       while(tx>=0 and ty>=0)
       {
         if(dp[tx][ty]=='Q') return false;
         tx--;
         ty++;
       }
       return true;

    }
    void helper(int row,vector<vector<string>>&ans,vector<string>&dp,vector<bool>&rowsOccupied,vector<bool>&colsOccupied,int n)
    {
        if(row==n)
        {
            ans.push_back(dp);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isValid( row,i,rowsOccupied,colsOccupied,n,dp))
            {
                rowsOccupied[row]=true;
                colsOccupied[i]=true;
                dp[row][i]='Q';
                helper( row+1,ans,dp,rowsOccupied,colsOccupied,n);
                dp[row][i]='.';
                rowsOccupied[row]=false;
                colsOccupied[i]=false;

            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string str="";
        for(int i=0;i<n;i++)
        {
           str.push_back('.');
        }
        vector<vector<string>>ans;
        vector<bool>rowsOccupied(n,false);
        vector<bool>colsOccupied(n,false);
        vector<string>dp(n,str);
        
        helper(0,ans,dp,rowsOccupied,colsOccupied,n);
        return ans;

    }
};