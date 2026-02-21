// https://www.geeksforgeeks.org/problems/word-break1352/1
class Solution {
  public:
    static bool comp(string& s1,string& s2)
    {
        return s1.size()<s2.size();
    }
    bool checker(int i,int j,string& s1,string& s2)
    {
        if(j-i+1<s2.size()) return false;
        int x=i;
        for(char ch:s2)
        {
            if(ch!=s1[x++])
            {
                return false;
            }
        }
        return true;
    }
    bool helper2(int index,string &s,vector<string> &dictionary,int n,vector<int>&dp)
    {
        
       int sz=s.size();
       if(index>=sz) return true;
       if(dp[index]!=-1) return dp[index];
       for(int i=0;i<n;i++)
       {
           if(dictionary[i].size()>sz-index) return dp[index]=false;
           if( checker(index,sz-1,s,dictionary[i]))
           {
               bool a=helper2(index+dictionary[i].size(),s,dictionary, n,dp);
               if(a) return dp[index]=true;
           }
       }
       return dp[index]=false;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
       
       
       
       int n=dictionary.size();
       sort(dictionary.begin(),dictionary.end(),comp);
       vector<int>dp(s.size(),-1);
       return helper2(0,s,dictionary, n,dp);
       
    }
};