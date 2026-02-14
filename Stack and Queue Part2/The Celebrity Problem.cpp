// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
       int n=mat.size();
       int i=0;
       int j=n-1;
       while(i<j)
       {
           if(mat[i][j]==1)
           {
               i++;
           }
           else if(mat[j][i]==1)
           {
               j--;
           }
           else
           {
               i++;
               j--;
           }
       }
       if(i>j) return -1;
       for(int x=0;x<n;x++)
       {
           if(i==x) continue;
           
           if(mat[i][x]==0 and mat[x][i]==1)
           {
               continue;
           }
           else
           {
               return -1;
           }
       }
       return i;
    }
};