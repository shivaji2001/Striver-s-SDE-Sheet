// https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
class Solution {
  public:
    int helper(int index,int requiredSum,vector<int>& arr,int n,vector<vector<int>>&dp)
    {
        //cout<<"Print"<<endl;
        if(index>=n and requiredSum==0) return 1;
        if(index>=n and requiredSum>0) return 0;
        
        if(requiredSum==0) return 1;
        if(requiredSum<0) return 0;
        if(dp[index][requiredSum]!=-1) return dp[index][requiredSum];
        bool take=helper( index+1, requiredSum-arr[index],arr,n,dp);
        bool nottake=helper(index+1,requiredSum,arr,n,dp);
        if(take or nottake) return dp[index][requiredSum]=1;
        return dp[index][requiredSum]=0;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n=arr.size();
        
        int mini=*min_element(arr.begin(),arr.end());
        int sum_of_elements=accumulate(arr.begin(),arr.end(),0);
        if(sum_of_elements<sum or sum<mini) return false;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return helper(0,sum,arr,n,dp)==1?true:false;
    }
};