// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
class Solution {
  public:
    bool isValid(int x,int y,int n,int m,vector<vector<int>>& maze)
    {
        if(x>=0 and y>=0 and x<n and y<m and maze[x][y]==1)
        return true;
        
        return false;
    }
    void helper(int x,int y,vector<string>&ans,string& path,vector<vector<int>>& maze,int n,int m)
    {
        //cout<<"x and y are:-"<<x<<" "<<y<<endl;
        if(x>=n or y>=m or x<0 or y<0) return;
        
        if(x==n-1 and y==m-1)
        {
           ans.push_back(path);
           return;
        }
        
        if( isValid(x+1,y,n,m,maze) )
        {
            maze[x][y]=-1;
            path.push_back('D');
            helper(x+1,y,ans,path,maze,n,m);
            path.pop_back();
            maze[x][y]=1;
        }
        if( isValid(x,y-1,n,m,maze) )
        {
            maze[x][y]=-1;
            path.push_back('L');
            helper(x,y-1,ans,path,maze,n,m);
            path.pop_back();
            maze[x][y]=1;
        }
        if( isValid(x,y+1,n,m,maze) )
        {
            maze[x][y]=-1;
            path.push_back('R');
            helper(x,y+1,ans,path,maze,n,m);
            path.pop_back();
            maze[x][y]=1;
        }
        if( isValid(x-1,y,n,m,maze) )
        {
            maze[x][y]=-1;
            path.push_back('U');
            helper(x-1,y,ans,path,maze,n,m);
            path.pop_back();
            maze[x][y]=1;
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        string path="";
        vector<string>ans;
        int n=maze.size();
        int m=maze[0].size();
        //cout<<"n a m are:"<<n<<" "<<m<<endl;
        helper(0,0,ans,path,maze,n,m);
        return ans;
        
    }
};