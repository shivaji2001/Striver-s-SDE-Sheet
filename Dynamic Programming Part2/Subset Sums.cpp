class Solution {
  public:
    void helper(int ind,int sum,vector<int>& arr,int n,vector<int>&ans)
    {
        if(ind>=n)
        {
            ans.push_back(sum);
            return;
        }
        
        helper(ind+1,sum,arr,n,ans);
        helper(ind+1,sum+arr[ind],arr,n,ans);
    }
    vector<int> subsetSums(vector<int>& arr) 
    {
        vector<int>ans;
        int n=arr.size();
        helper(0,0,arr,n,ans);
        return ans;
       
    }
};