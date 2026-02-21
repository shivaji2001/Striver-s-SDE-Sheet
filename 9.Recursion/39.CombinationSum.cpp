// https://leetcode.com/problems/combination-sum/description/


class Solution {
public:
    // void helper(int ind,vector<int>&temp,int sum,vector<int>& candidates,int target,vector<vector<int>>&ans){
    //     int n=candidates.size();
    //     if(sum==target)
    //     {
    //         ans.push_back(temp);
    //         return;
    //     }
    //     for(int i=ind;i<n;i++)
    //     {
    //        if(i!=ind and candidates[i]==candidates[i-1])
    //         continue;
    //        if(sum+candidates[i]>target)
    //         return;
    //        temp.push_back(candidates[i]);
    //        helper(i,temp,sum+candidates[i],candidates,target,ans);
    //        temp.pop_back();
    //     }
    // }
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    // {
    //     int n=candidates.size();
    //     sort(candidates.begin(),candidates.end());
    //     vector<vector<int>>ans;
    //     vector<int>temp;
    //     helper(0,temp, 0,candidates, target,ans);
    //     return ans;

    // }
    void helper2(int ind,vector<int>&candidates,int target,int n,vector<vector<int>>&ans,vector<int>&temp)
    {
        if(ind>=n) return;
        if(target<0) return;
        if(target==0)
        {
           ans.push_back(temp);
           return;
        }
        temp.push_back(candidates[ind]);
        helper2(ind,candidates,target-candidates[ind], n,ans,temp);
        temp.pop_back();
        helper2(ind+1,candidates,target, n,ans,temp);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper2(0,candidates,target, n,ans,temp);
        return ans;

    }
};