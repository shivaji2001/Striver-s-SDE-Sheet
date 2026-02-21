// https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1
class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>nse(n,-1);
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
                while(!st.empty() and nums[i]<nums[st.top()])
                {
                    int ind=st.top();
                    st.pop();
                    nse[ind]=i;
                }
                st.push(i);
        }
        while(!st.empty())
        {
            int ind=st.top();
            st.pop();
            nse[ind]=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(nse[i]!=-1)
            {
                nse[i]=nums[nse[i]];
            }
        }
        return nse;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<nge[i]<<" ";
        // }
        // cout<<endl;
        // unordered_map<int,int>um;
        // for(int i=0;i<n;i++)
        // {
        //     if(nge[i]==-1)
        //     {
        //       um[nums2[i]]=-1;
        //     }
        //     else {
        //         um[nums2[i]]=nums2[nge[i]];
        //     }
        // }
        
        // vector<int>ans;
        // for(int a:nums1)
        // {
        //   ans.push_back(um[a]);
        // }
        

        // return ans;
    }
    vector<int> nextSmallerEle(vector<int>& arr) {
        return nextGreaterElement(arr) ;
        
    }
};