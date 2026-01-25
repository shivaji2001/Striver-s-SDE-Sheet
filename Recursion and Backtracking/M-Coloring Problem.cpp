// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
class Solution {
  public:
   
    void helper2(int index,vector<int>&colorOfV,int v,map<int,vector<int>>&adj,int m,bool& ans)
    {
        if(index==v)
        {
            ans=true;
            return;
        }
        if(ans==true) return;
        for(int i=1;i<=m;i++)
        {
            bool colorFound=true;
            for(int a:adj[index])
            {
                if(colorOfV[a]==i)
                {
                    colorFound=false;
                    break;
                }
            }
            if(colorFound==true)
            {
                colorOfV[index]=i;
                helper2(index+1,colorOfV, v,adj,m,ans);
                colorOfV[index]=-1;
            }
            
        }
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        
        map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        vector<int>colorOfV(v,-1);
        
        bool ans=false;
        helper2(0,colorOfV, v,adj, m, ans);
        return ans;
        
    }
};