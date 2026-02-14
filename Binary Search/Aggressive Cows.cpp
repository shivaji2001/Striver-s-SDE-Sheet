// https://www.geeksforgeeks.org/problems/aggressive-cows/1

class Solution {
  public:
    bool canWePlace(int dist,vector<int> &stalls,int k)
    {
        // int n=stalls.size();
        // int x=0;
        // int count=1;
        // while(x<n)
        // {
        //     int nextNumber=stalls[x]+dist;
        //     int nextInd=lower_bound(stalls.begin(),stalls.end(),nextNumber)-stalls.begin();
        //     if(nextInd<n)
        //     {
        //         count++;
        //         if(count>=k) return true;
                
        //     }
        //     x=nextInd;
            
        // }
        // return count>=k;
        int cntCows=1;
        int last=stalls[0];
        for(int i=1;i<stalls.size();i++)
        {
            if(stalls[i]-last>=dist)
            {
                cntCows++;
                last=stalls[i];
            }
            if(cntCows>=k) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) 
    {
      sort(stalls.begin(),stalls.end());
      int n= stalls.size();
      int mini=INT_MAX;
      for(int i=1;i<n;i++)
      {
          mini=min(mini,stalls[i]-stalls[i-1]);
      }
      int lo=mini;
      int hi=stalls[n-1]-stalls[0];
      while(hi-lo>1)
      {
          int mid=(lo+hi)/2;
          int count=0;
          
          if(canWePlace(mid,stalls, k))
          {
              lo=mid;
          }
          else
          {
              hi=mid-1;
          }
      }
      
      if(canWePlace(hi,stalls,k))
        return hi;
      else
        return lo;
      
      
      
       
        
    }
};