class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n=nums.size();
        int low=0;
        int med=0;
        int high=n-1;
        while(med<=high)
        {
            if(nums[med]==0)
            {
              swap(nums[low],nums[med]);
              low++;
              med++;
            }
            else if(nums[med]==1)
            {
                med++;
            }
            else
            {
                swap(nums[med],nums[high]);
                high--;
            }
        }
    }
};