// https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
class Solution {
  public:
    static bool comp(pair<double,pair<int,int>>&p1,pair<double,pair<int,int>>&p2)
    {
        return p1.first>p2.first;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
    {
       int n=val.size();
       vector<pair<double,pair<int,int>>>vp;
       for(int i=0;i<n;i++)
       {
           int a=val[i];
           int b=wt[i];
           double c=(double)a/(double)b;
           vp.push_back({c,{a,b}});
       }
       sort(vp.begin(),vp.end(),comp);
       double ans=0;
       for(int i=0;i<n;i++)
       {
           
           if(vp[i].second.second <= capacity)
           {
               ans+=vp[i].second.first;
               capacity-=vp[i].second.second;
           }
           else
           {
               double a=vp[i].second.first;
               double b=vp[i].second.second;
               double c= a*capacity/b;
               ans+=  c;
               capacity=0;
               break;
           }
       }
       return ans;
        
        
    }
};
