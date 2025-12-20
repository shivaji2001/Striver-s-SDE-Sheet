class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           queue<char>q;
           int n=s.size();
           int ans=0;
           unordered_set<char>st;
           for(char ch:s)
           {
              if(st.find(ch)==st.end())
              {
                q.push(ch);
                st.insert(ch);
              }
              else
              {
                while(q.size()>0 and q.front()!=ch)
                {
                    char c=q.front();
                    q.pop();
                    st.erase(c);
                }
                
                q.pop();
                
                q.push(ch);
                

              }
              ans=max(ans,(int)q.size());
           }
           return ans;
    }
};