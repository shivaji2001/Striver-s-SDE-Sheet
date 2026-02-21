// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
class Solution {
  public:
    static bool comp(pair<int,int>&p1,pair<int,int>&p2)
    {
        return p1.second<p2.second;
    }
    int findIndex(int deadline,vector<int>&timeStamp)
    {
        for(int i=deadline;i>=0;i--)
        {
            if(timeStamp[i]==0)
            {
                return i;
            }
        }
        return -1;
    }
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n=deadline.size();
        vector<pair<int,int>>vp;
        int maxi=*max_element(deadline.begin(),deadline.end());
        vector<int>timeStamp(maxi,0);
        for(int i=0;i<n;i++)
        {
            vp.push_back({deadline[i]-1,profit[i]});
        }
        sort(vp.begin(),vp.end(),comp);
        int ans=0;
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            int deadln=vp[i].first;
            int prof=vp[i].second;
            int index=findIndex(deadln,timeStamp);
            if(index!=-1)
            {
                ans+=prof;
                count++;
                timeStamp[index]=prof;
            }
        }
        return {count,ans};
        
          
    }
};