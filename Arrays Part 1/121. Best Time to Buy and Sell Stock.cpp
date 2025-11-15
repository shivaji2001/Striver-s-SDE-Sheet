class Solution {
public:
    int maxProfit(vector<int>& prices)
     {
        int min_so_far=INT_MAX;
        int ans=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            min_so_far=min(min_so_far,prices[i]);
            if(prices[i]-min_so_far>ans)
            {
                ans=prices[i]-min_so_far;
            }
        }
        return ans;
    }
};