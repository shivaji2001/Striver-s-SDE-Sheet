// https://leetcode.com/problems/top-k-frequent-elements/description/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int n=nums.size();
        unordered_map<int,int>um;
        for(int i=0;i<n;i++)
        {
           um[nums[i]]++; 
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        for(auto it:um)
        {
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k--)
        {
          ans.push_back(pq.top().second);
          pq.pop();
        }
        return ans;



    }
};