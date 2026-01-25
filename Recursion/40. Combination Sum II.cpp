// https://leetcode.com/problems/combination-sum-ii/submissions/1888238788/


class Solution {
public:
    
    void helper(int ind,vector<int>&temp,int sum,vector<int>& candidates,int target,vector<vector<int>>&ans){
        int n=candidates.size();
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++)
        {
           if(i!=ind and candidates[i]==candidates[i-1])
            continue;
           if(sum+candidates[i]>target)
            return;
           temp.push_back(candidates[i]);
           helper(i+1,temp,sum+candidates[i],candidates,target,ans);
           temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0,temp, 0,candidates, target,ans);
        return ans;

    }
    
};