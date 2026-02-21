// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
class Solution {
  public:
    int pow(int x,int n)
    {
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*x;
        }
        return ans;
    }
    int nthRoot(int n, int m) {
        int lo=1;
        int hi=m;
        while(hi-lo>1)
        {
            int mid=lo+(hi-lo)/2;
            int po=pow(mid,n);
            if( po==m )
            {
                return mid;
            }
            else if(po<m)
            {
                lo=mid+1;
            }
            else
            {
                hi=mid;
            }
        }
        if(pow(lo,n)==m) return lo;
        else if(pow(hi,n)==m) return hi;
        else return -1;
    }
};