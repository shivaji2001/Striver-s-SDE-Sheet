// R
// https://www.geeksforgeeks.org/problems/sort-a-stack/1
class Solution {
  public:
    void sortStack(stack<int> &st) 
    {
        stack<int>st1;
        stack<int>st2;
        while(!st.empty())
        {
            int a=st.top();
            st.pop();
            while(!st1.empty() and st1.top()<a)
            {
                int x=st1.top();
                st2.push(x);
                st1.pop();
            }
            st1.push(a);
            while(!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
            
            
            
        }
        while(!st1.empty())
        {
            st.push(st1.top());
            st1.pop();
        }
        
        
        
    }
};