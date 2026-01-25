// https://leetcode.com/problems/subsets-ii/submissions/1888116624/

class Solution {
public:
    void helper(int ind,vector<int>&temp,vector<int>& nums,vector<vector<int>>&ans)
    {
       int n=nums.size();
       ans.push_back(temp);
       for(int i=ind;i<n;i++)
       {
         if(i!=ind and nums[i]==nums[i-1])
         {
            continue;
         }
         temp.push_back(nums[i]);
         helper(i+1,temp,nums,ans);
         temp.pop_back();
       }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<int>temp;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        helper(0,temp,nums,ans);
        return ans;
        
    }
};