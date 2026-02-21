class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int lo=0;
        int hi=n-1;
        while(hi-lo>1)
        {
            int mid=lo+ (hi-lo)/2;
            if(matrix[mid][0]>target)
            {
                hi=mid-1;
            }
            else
            {
                lo=mid;
            }
        }
        int requiredRow=0;
        if(target>=matrix[hi][0]  )
        {
              requiredRow=hi;
        }
        else
        {
            requiredRow=lo; 
        }
        lo=0;
        hi=m-1;
        while(hi-lo>1)
        {
           int mid=lo+ (hi-lo)/2;
           if(matrix[requiredRow][mid]>target)
           {
             hi=mid-1;
           }
           else
           {
            lo=mid;
           }
        }
        cout<<"RR lo hi"<<requiredRow<<" "<<lo<<" "<<hi<<endl;
        if(matrix[requiredRow][lo]==target)
        {
            return true;
        }
        else if(matrix[requiredRow][hi]==target)
        {
            return true;
        }
        return false;

    }
};