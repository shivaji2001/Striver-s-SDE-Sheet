class Solution {
public:
    long long ans=0;
    void merge(vector<int>& nums,long long i,long long mid,long long j)
    {
        long long sz=j-i+1;
        vector<long long>temp(sz);
        long long x=0;
        long long y=i;
        long long z=mid+1;
        for(long long tmp=mid+1;tmp<=j;tmp++)
        {
               long long req=2LL*(long long)nums[tmp];
               long long index=upper_bound(nums.begin()+i,nums.begin()+mid+1,req)-nums.begin();
               ans+=mid-index+1;
                
        }
        
        while(y<=mid and z<=j)
        {
               
            
            if(nums[y]<=nums[z])
            {
                temp[x]=nums[y];
                x++;
                y++;
            }
            else
            {
               

                temp[x]=nums[z];
                x++;
                z++;
            }
        }
        while(y<=mid)
        {
            temp[x]=nums[y];
            x++;
            y++;
        }
        while(z<=j)
        {
            temp[x]=nums[z];
            x++;
            z++;
        }
        x=0;
        for(int l=i;l<=j;l++)
        {
            nums[l]=temp[x];
            
            x++;
        }
    }
    void mergeSort(vector<int>& nums,long long i,long long j)
    {
        if(i>=j) return ;
        long long mid=(i+j)/2;
        mergeSort(nums,i,mid);
        mergeSort(nums,mid+1,j);
        merge(nums,i,mid,j);
        
    }
    int reversePairs(vector<int>& nums) {
        ans=0;
        long long n=nums.size();
        mergeSort(nums,0,n-1);
        
        return ans;
    }
};