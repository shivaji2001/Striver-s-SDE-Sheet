// R
// https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1
class Solution {
  public:
    int maxProduct(vector<int> &arr) 
    {
        // int n=arr.size();
        
        // int ans=INT_MIN;
        // vector<int>pref(n,1);
        // vector<int>suff(n,1);
        // pref[0]=arr[0];
        // suff[n-1]=arr[n-1];
        // for(int i=0;i<n;i++)
        // {
        //     if(i>=1 and arr[i]!=0)
        //     {
        //         pref[i]=arr[i]*pref[i-1];   
        //     }
        // }
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(i<=n-2 and arr[i]!=0)
        //     {
        //         suff[i]= arr[i]*suff[i+1];   
        //     }
        // }
        
        // for(int i=0;i<n-1;i++)
        // {
        //     int prod=pref[i]*suff[i+1];
        //     ans=max(ans,prod);
        //     // cout<<suff[i]<<" ";
            
        // }
        // return ans;
        int n=arr.size();
        int ans=INT_MIN;
        int pref=1;
        int suff=1;
        for(int i=0;i<n;i++)
        {
            if(pref==0) pref=1;
            if(suff==0) suff=1;
            pref=pref*arr[i];
            suff=suff*arr[n-i-1];
            // int prod=pref*suff;
            ans=max(ans,max(pref,suff));
            
        }
        return ans;
        
    }
};