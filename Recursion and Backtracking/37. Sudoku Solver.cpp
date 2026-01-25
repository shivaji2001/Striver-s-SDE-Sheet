// https://leetcode.com/problems/sudoku-solver/description/
class Solution {
public:
    vector<vector<char>>ans;
    pair<int,int> baseIndexFinder(int x,int y)
    {
        x=x/3;
        y=y/3;
        x=x*3;
        y=y*3;
        return {x,y};
    }
    bool isValid(int num,int x,int y,map<int,set<int>>&rowData,map<int,set<int>>&colData,map<pair<int,int>,set<int>>&gridData)
    {
        if(rowData[x].find(num)!=rowData[x].end()) return false;
        if(colData[y].find(num)!=colData[y].end()) return false;
        pair<int,int>p=baseIndexFinder(x, y);
        int row=p.first;
        int col=p.second;
        
        if(gridData[{row,col}].find(num)!=gridData[{row,col}].end())
        {
            return false;
        }
        return true;
    }
    pair<int,int>nextIndex(int x,int y,vector<vector<char>>&board)
    {
        if(y!=8)
        {
            return {x,y+1};
        }
        return {x+1,0};
    }
    
    void helper(int row,int col,map<int,set<int>>&rowData,map<int,set<int>>&colData,map<pair<int,int>,set<int>>&gridData,
    vector<vector<char>>&tempBoard,vector<vector<char>>&board,bool&solnFound)
    {
        if(row==9)
        {
            solnFound=true;
            ans=tempBoard;
            return;
        }
        if(solnFound) return;
        if(board[row][col]!='.')
        {
            pair<int,int>p=nextIndex(row, col,board);
            helper(p.first, p.second,rowData,colData,gridData,tempBoard,board,solnFound);
        }
        else
        {
            for(int k=1;k<=9;k++)
            {
                if(isValid(k,row,col,rowData,colData,gridData))
                {
                   rowData[row].insert(k);
                   colData[col].insert(k);
                   pair<int,int>p=baseIndexFinder(row, col);
                   gridData[p].insert(k);
                   tempBoard[row][col]='0'+k;
                   pair<int,int>pp=nextIndex(row,col,board);
                   helper(pp.first,pp.second,rowData,colData,gridData,tempBoard,board,solnFound);
                   tempBoard[row][col]='.';
                   gridData[p].erase(k);
                   colData[col].erase(k);
                   rowData[row].erase(k);

                }
            }
        }
        
        // for(int j=0;j<9;j++)
        // {
        //     for(int k=1;k<=9;k++)
        //     {
        //         if(isValid(k,row,j,rowData,colData,gridData))
        //         {
        //            rowData[row].insert(k);
        //            colData[j].insert(k);
        //            pair<int,int>p=baseIndexFinder(row, j);
        //            gridData[p].insert(k);
        //         }
                
        //     }
        // }
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
       ans.clear();
       vector<vector<char>>tempBoard=board;
       map<int,set<int>>rowData;
       map<int,set<int>>colData;
       map<pair<int,int>,set<int>>gridData;
       for(int i=0;i<9;i++)
       {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]!='.')
            {
                rowData[i].insert( board[i][j]-'0'   );
                colData[j].insert( board[i][j]-'0'   );
                pair<int,int>p=baseIndexFinder(i,j);
                gridData[p].insert( board[i][j]-'0' );

            }
        }
       }
       bool solnFound=false;
       helper(0,0,rowData,colData,gridData,tempBoard,board,solnFound);
       board=ans;

        
    }
};