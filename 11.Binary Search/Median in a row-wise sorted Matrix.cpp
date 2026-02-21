// R
// https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
class Solution {
  public:
    int findLesser(int x,vector<vector<int>> &mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            int index=upper_bound(mat[i].begin(),mat[i].end(),x)-mat[i].begin();
            
            count+=index;
            
        }
        return count;
    }
   
    int median(vector<vector<int>> &mat) 
    {
       int n=mat.size();
       int m=mat[0].size();
       int mini=INT_MAX;
       int maxi=INT_MIN;
       for(int i=0;i<n;i++)
       {
           mini=min(mini,mat[i][0]);
           maxi=max(maxi,mat[i][m-1]);
       }
       int lo=mini;
       int hi=maxi;
       int required=(n*m)/2;
       while(hi-lo>1)
       {
           int mid=lo+(hi-lo)/2;
           
           if(findLesser(mid,mat)<=required)
           {
               lo=mid+1;
           }
           else
           {
               hi=mid;
           }
           
       }
       if(findLesser(lo,mat)>required) return lo;
       else return hi;
    }
};