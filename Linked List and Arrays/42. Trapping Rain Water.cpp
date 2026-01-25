class Solution {
public:
    // vector<int>next_greater(vector<int>nums)
    // {
    //     int n=nums.size();
    //     stack<int>st;
    //     vector<int>ans(n,-1);
    //     for(int i=0;i<n;i++)
    //     {
    //        if(st.empty())
    //        {
    //         st.push(i);
    //        }
    //        else
    //        { 
    //           while(!st.empty() and nums[st.top()]<nums[i]  )
    //           {
    //              int ind=st.top();
    //              st.pop();
    //              ans[ind]=i;
    //           }
    //           st.push(i);
    //        }
    //     }
    //     return ans;
    // }
    // vector<int>next_smaller(vector<int>nums)
    // {
    //     int n=nums.size();
    //     stack<int>st;
    //     vector<int>ans(n,-1);
    //     for(int i=n-1;i>=0;i--)
    //     {
    //        if(st.empty())
    //        {
    //         st.push(i);
    //        }
    //        else
    //        {
    //           while(!st.empty() and nums[st.top()]<nums[i]  )
    //           {
    //              int ind=st.top();
    //              st.pop();
    //              ans[ind]=i;
    //           }
    //           st.push(i);
    //        }
    //     }
    //     return ans;
    // }
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>ngi(n,-1);
        vector<int>nsi(n,-1);
        int maxi=INT_MIN;
        int index=-1;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(height[i]>maxi)
            {
                maxi=height[i];
                index=i;
            }
            else if(height[i]<maxi)
            {
                ngi[i]=index;
            }
        }

        maxi=INT_MIN;
        index=-1;
        for(int i=0;i<n;i++)
        {
            if(height[i]>maxi)
            {
                maxi=height[i];
                index=i;
            }
            else if(height[i]<maxi)
            {
                nsi[i]=index;
            }
        }
        cout<<"nsi"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<nsi[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
           if(ngi[i]!=-1 and nsi[i]!=-1)
           {
            int minHeight=min(height[ngi[i]],height[nsi[i]])-height[i];
            
            ans+=minHeight;
           }
        }
        

        
        
        return ans;
        
    }
};
