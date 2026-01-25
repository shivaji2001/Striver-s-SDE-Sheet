class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comp(pair<int,int>&p1,pair<int,int>&p2)
    {
        if(p1.second!=p2.second) return p1.second<p2.second;
        return p1.first<p2.first;
    }
    int maxMeetings(vector<int>& start, vector<int>& end)
    {
        vector<pair<int,int>>v;
        int n=start.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        int ans=0;
        int last=-1;
        for(int i=0;i<n;i++)
        {
            if(v[i].first>last)
            {
                ans++;
                last=v[i].second;
            }
        }
        return ans;
        
        
    }
};