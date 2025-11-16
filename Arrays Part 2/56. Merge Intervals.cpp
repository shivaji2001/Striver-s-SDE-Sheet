class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int start=0;
        int end=0;
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else
            {
                if(intervals[i][0]<=end)
                {
                    end=max(end,intervals[i][1]);
                }
                else
                {
                    ans.push_back({start,end});
                    start=intervals[i][0];
                    end=intervals[i][1];
                }
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};