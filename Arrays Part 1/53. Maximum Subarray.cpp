class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSumTillNow=*max_element(nums.begin(),nums.end());
        int ans=nums[0];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(maxSumTillNow<sum)
            {
                maxSumTillNow=sum;
            }
            else
            {
                if(sum<0)
                {
                    sum=0;
                }
            }

        }
        return maxSumTillNow;

    }
};