class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int n1=-1;
        int c1=0;
        int n2=-1;
        int c2=0;
        for(int i=0;i<n;i++)
        {
             if(c1==0 and nums[i]!=n2)
             {
                c1++;
                n1=nums[i];
             }
             else if(c2==0 and nums[i]!=n1)
             {
                c2++;
                n2=nums[i];
             }
             else if(nums[i]==n1)
             {
                c1++;
             }
             else if(nums[i]==n2)
             {
                c2++;
             }
             else
             {
                c1--;
                c2--;
             }
        }
        c1=0;
        c2=0;
        for(int a:nums)
        {
            if(a==n1) c1++;
            else if(a==n2) c2++;
        }
        vector<int>ans;
        
        if(c1>=n/3+1) ans.push_back(n1);
        if(c2>=n/3+1) ans.push_back(n2);
        sort(ans.begin(),ans.end());
        return ans;
    }
};