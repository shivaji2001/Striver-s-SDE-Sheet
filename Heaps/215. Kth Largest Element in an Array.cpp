// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int n=nums.size();
        priority_queue<int,vector<int>>pq;
        for(int a:nums)
        {
            pq.push(a);
        }
        int ans;
        while(k--)
        {
            ans=pq.top();
            pq.pop();
        }
        return ans;

    }
};