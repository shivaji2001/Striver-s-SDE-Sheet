class Solution {
  public:
    int maxLength(vector<int>& arr) {
        int sum=0;
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(mp.find(sum)==mp.end())
            {
                mp[sum]=i;
            }
            else
            {
                ans=max(ans,i-mp[sum]);
            }
        }
        return ans;
        
    }
};