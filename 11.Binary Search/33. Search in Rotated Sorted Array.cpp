// R
// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(hi-lo>1)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[lo]<=nums[mid] and nums[mid+1]<=nums[hi])
            {
               if(target>=nums[lo] and target<=nums[mid])
               {
                 hi=mid;
               }
               else
               {
                lo=mid+1;
               }
            }
            else if(nums[lo]<=nums[mid])
            {
               if(target>=nums[lo] and target<=nums[mid])
               {
                 hi=mid;
               }
               else
               {
                 lo=mid+1;
               }
            }
            else
            {
               if(target>=nums[mid+1] and target<=nums[hi])
               {
                 lo=mid+1;
               }
               else
               {
                 hi=mid;
               }
            }

        }
        if(nums[lo]==target) return lo;
        else if(nums[hi]==target) return hi;
        return -1;
    }
};