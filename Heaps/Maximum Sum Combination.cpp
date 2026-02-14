// R
// https://www.geeksforgeeks.org/problems/maximum-sum-combination/1
class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k)
    {
       int n=a.size();
       vector<int>ans;
       set<pair<int,int>>s;
       sort(a.begin(),a.end());
       sort(b.begin(),b.end());
       
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>>pq;
       pq.push( {a[n-1]+b[n-1],{n-1,n-1}}  );
       s.insert({n-1,n-1});
       
       while(k--)
       {
           auto it=pq.top();
           pq.pop();
           ans.push_back(it.first);
           int x=it.second.first;
           int y=it.second.second;
           if(s.find({x-1,y})==s.end())
           {
               pq.push({a[x-1]+b[y],{x-1,y}});
               s.insert({x-1,y});
           }
           if(s.find({x,y-1})==s.end())
           {
               pq.push({a[x]+b[y-1],{x,y-1}});
               s.insert({x,y-1});
           }
           
       }
       sort(ans.begin(),ans.end(),greater<int>());
       return ans;
       
    }
};