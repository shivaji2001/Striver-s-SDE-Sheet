class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int fre=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]==ans)
            {
                fre++;
            }
            else
            {
                fre--;
                if(fre==0)
                {
                    ans=nums[i];
                    fre=1;
                }
            }
        }
        return ans;
    }
};