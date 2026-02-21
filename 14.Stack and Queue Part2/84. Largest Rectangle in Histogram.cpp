// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int n=heights.size();
        vector<int>nsi(n,n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and heights[st.top()]>heights[i])
            {
                int index=st.top();
                st.pop();
                nsi[index]=i;
            }
            st.push(i);
        }
        vector<int>prevsi(n,-1);
        stack<int>st2;
        for(int i=n-1;i>=0;i--)
        {
            while(!st2.empty() and heights[st2.top()]>heights[i])
            {
                int index=st2.top();
                st2.pop();
                prevsi[index]=i;
            }
            st2.push(i);
        }
        for(int a:prevsi)
        {
            cout<<a<<" ";
        }
        cout<<endl;
        int maxi=*max_element(heights.begin(),heights.end());
        for(int i=0;i<n;i++)
        {
           int area= (nsi[i]-prevsi[i]-1)*heights[i];
           maxi=max(maxi,area);
        }
        return maxi;
        
    }
};