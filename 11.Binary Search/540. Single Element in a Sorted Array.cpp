// https://leetcode.com/problems/single-element-in-a-sorted-array/description/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(hi-lo>=2)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]!=nums[mid-1] and nums[mid]!=nums[mid+1] )
            {
                return nums[mid];
            }
            else if( nums[mid]==nums[mid-1] )
            {
                if(mid%2==1)
                {
                    lo=mid+1;
                }
                else
                {
                    hi=mid-2;
                }
            }
            else
            {
                if(mid%2==1)
                {
                    hi=mid-1;
                }
                else
                {
                    lo=mid+2;
                }
            }
        }
        return nums[lo];
        
    }
};