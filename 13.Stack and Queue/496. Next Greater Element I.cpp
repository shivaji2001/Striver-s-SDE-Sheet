// https://leetcode.com/problems/next-greater-element-i/description/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n=nums2.size();
        vector<int>nge(n,-1);
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
           if(st.empty())
           {
              st.push(i);
           }
           else
           {
              if(nums2[i]>nums2[st.top()])
              {
                while(!st.empty() and nums2[i]>nums2[st.top()])
                {
                    int ind=st.top();
                    st.pop();
                    nge[ind]=i;
                }
                st.push(i);
              }
              else
              {
                st.push(i);
              }
           }
        }
        while(!st.empty())
        {
            int ind=st.top();
            st.pop();
            nge[ind]=-1;
        }
        for(int i=0;i<n;i++)
        {
            cout<<nge[i]<<" ";
        }
        cout<<endl;
        unordered_map<int,int>um;
        for(int i=0;i<n;i++)
        {
            if(nge[i]==-1)
            {
               um[nums2[i]]=-1;
            }
            else {
                um[nums2[i]]=nums2[nge[i]];
            }
        }
        
        vector<int>ans;
        for(int a:nums1)
        {
           ans.push_back(um[a]);
        }
        

        return ans;
    }
};