// https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
class Solution {
  public:
    static bool comp(pair<float,pair<int,int>>&p1,pair<float,pair<int,int>>&p2)
    {
        return (float)p1.first>(float)p2.first;
    }
    int helper(int i,int w,vector<int> &val, vector<int> &wt,vector<vector<int>>&dp)
    {
        int n=val.size();
        if(i>=n) return 0;
        if(w<=0) return 0;
        if(dp[i][w]!=-1) return dp[i][w];
        int take= w>=wt[i]? val[i]+helper(i+1,w-wt[i],val,wt,dp) :0;
        int ntake= helper(i+1,w,val,wt,dp);
        return dp[i][w]=max(take,ntake);
    }
    int knapsack(int w, vector<int> &val, vector<int> &wt) 
    {
        int n=val.size();
        // vector<pair<float,pair<int,int>>>vp;
        // for(int i=0;i<n;i++)
        // {
        //     float a=(float)val[i]/(float)wt[i];
        //     vp.push_back({a,{val[i],wt[i]}});
        // }
        // sort(vp.begin(),vp.end(),comp);
        // int ans=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(vp[i].second.second<=W)
        //     {
        //         W-=vp[i].second.second;
        //         ans+=vp[i].second.first;
        //     }
        // }
        vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
        return helper(0,w,val,wt,dp);
        
        
    }
};