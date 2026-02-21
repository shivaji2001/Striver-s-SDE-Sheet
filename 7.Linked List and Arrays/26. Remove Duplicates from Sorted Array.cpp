class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        
        int u=0;
        for(int i=0;i<n;i++)
        {
          int start=i;
          int end=i;
          while(end+1<n and nums[end+1]==nums[start])
          {
            end++;
          }
          nums[u]=nums[end];
          u++;
          i=end; 
        }
        return u;
     
    }
};