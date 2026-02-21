// R
// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution {
  public:
    vector<int>ngeInLeft(vector<int>& arr)
    {
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and arr[st.top()]<arr[i])
            {
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
        
    }
    vector<int> calculateSpan(vector<int>& arr) {
        
        vector<int>prevGreater=ngeInLeft(arr);
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            prevGreater[i]=i-prevGreater[i];
        }
        return prevGreater;
    }
};