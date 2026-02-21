//    https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
   bool isPalindrome(string str) {
    string rev = str;
    reverse(rev.begin(), rev.end());

    if (str == rev)
        return true;
    else
        return false;
}
    void helper(int ind,vector<string>temp,vector<vector<string>>& ans,string& s,int n)
    {
       if(ind==n)
       {
        ans.push_back(temp);
        return;
       }
         
       
       for(int i=ind;i<n;i++)
       {
          string s1=s.substr(ind,i-ind+1);
          
          bool a=isPalindrome(s1);
          
          if(!a) continue;

            temp.push_back(s1);
            helper( i+1,temp,ans,s,n);
            temp.pop_back();
          
       }
    }
    vector<vector<string>> partition(string s) 
    {
        // vector<vector<string>>ans;
        // int n=s.size();
        // vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
        // for(int i=0;i<n;i++)
        // {
        //    dp[i][i]=true;
        // }
        // for(int i=n-1;i>=0;i--)
        // {
        //     int diff=n-i-1;
        //     for(int j=0;j<=i;j++)
        //     {
        //        if(s[j]==s[j+diff] and dp[j-1][j+diff-1]==true)
        //        dp[j][j+diff]=true;
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         if(dp[i][j]==true)
        //         {
        //            string str=s.substr(i,j-i+1);
        //            ans.push_back(str);
        //         }
                
        //     }
        // }
        int n=s.size();

        vector<vector<string>>ans;
        vector<string>temp;
        if(n==1)
        {
            temp.push_back(s);
            ans.push_back(temp);
            return ans;
        }
        
        helper(0,temp,ans,s,n);
        return ans;
    }
};