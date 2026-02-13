// https://www.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

class Solution {
  public:
    int lis(vector<int>& arr) 
    {
        vector<int>ans;
        int n=arr.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            if(ans.size()==0)
            {
                ans.push_back(arr[i]);
            }
            else
            {
                if(ans[ans.size()-1]<arr[i])
                {
                    ans.push_back(arr[i]);
                }
                else
                {
                     int ind=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                     ans[ind]=arr[i];
                }
               
            }
            maxi=max(maxi,(int)ans.size());
        }
        return maxi;
        
    }
};