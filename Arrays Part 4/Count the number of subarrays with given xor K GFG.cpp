class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
       int n=arr.size();
       vector<int>temp;
       int xr=0;
       unordered_map<int,int>mp;
       int ans=0;
       mp[0]++;
       for(int a:arr)
       {
           xr=xr^a;
           if(mp.find(xr^k)!=mp.end()  )
           {
               ans+=mp[xr^k];
           }
           mp[xr]++;
       }
       return ans++;
       
    }
};