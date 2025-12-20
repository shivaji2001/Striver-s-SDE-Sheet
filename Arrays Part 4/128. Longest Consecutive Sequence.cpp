class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_set<int>st;
        for(int a:nums)
        {
            st.insert(a);
        }
        int ans=0;
        for(int a:st)
        {
            if(st.find(a-1)==st.end())
            {
                int cnt=1;
                int no=a;
                while(st.find(no+1)!=st.end())
                {
                    cnt++;
                    no++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
        
    }
};