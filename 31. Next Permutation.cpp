class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size();
        if (n == 1)
            return;
        int index = -1;
        // find any element from end so that any smaller element is present just before it
        for (int i = n - 1; i >= 1; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                index = i - 1;
                break;
            }
        }
        if (index != -1)
        {
            int nextGreaterValInd = index + 1;
            int nextGreaterVal = nums[index + 1];
            // checking for just greater element than nums[index]
            for (int i = index + 1; i < n; i++)
            {
                if (nums[i] < nextGreaterVal and nums[i] > nums[index])
                {
                    nextGreaterVal = nums[i];
                    nextGreaterValInd = i;
                }
            }
            swap(nums[index], nums[nextGreaterValInd]);
            sort(nums.begin() + index + 1, nums.end());
        }
        else
        {
            sort(nums.begin(), nums.end());
        }
    }
};