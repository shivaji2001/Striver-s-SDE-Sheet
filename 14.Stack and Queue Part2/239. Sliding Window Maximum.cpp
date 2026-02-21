// R
// https://leetcode.com/problems/sliding-window-maximum/description/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int n=nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            if(dq.empty())
            {
                 dq.push_back(i);
            }
            else if( i-dq.front()<k)
            {
                while(!dq.empty() and nums[dq.back()]<=nums[i])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            else
            {
                dq.pop_front();
                while(!dq.empty() and nums[dq.back()]<=nums[i])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            if(i>=k-1)
            ans.push_back(nums[dq.front()]);
        }
        return ans;

    }
};