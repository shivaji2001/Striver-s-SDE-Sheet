class Solution {
  public:
    int count=0;
    void merge(vector<int>&arr,int i,int mid,int j)
    {
        int x=i;
        int y=mid+1;
        vector<int>temp(j-i+1);
        int z=0;
        while(x<=mid and y<=j )
        {
            if(arr[x]<=arr[y])
            {
                temp[z++]=arr[x++];
               
            }
            else
            {
                count+=mid-x+1;
                temp[z++]=arr[y++];
                
            }
        }
        while(x<=mid)
        {
            temp[z++]=arr[x++];
          
        }
        while(y<=j)
        {
            temp[z++]=arr[y++];
           
        }
        z=0;
        for(int k=i;k<=j;k++)
        {
            arr[k]=temp[z++];
         
        }
    }
    int mergeSort(vector<int> &arr,int i,int j)
    {
        
        int mid=(i+j)/2;
        
        if(i<j)
        {
            mergeSort(arr, i,mid);
            mergeSort(arr, mid+1,j);
            merge(arr,i,mid,j);
        }
    }
    int inversionCount(vector<int> &arr) {
        count=0;
        int n=arr.size();
        
        mergeSort(arr, 0, n-1);
        return count;
        
    }
};