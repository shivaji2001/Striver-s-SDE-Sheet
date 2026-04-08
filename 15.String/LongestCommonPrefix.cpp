// https://leetcode.com/problems/longest-common-prefix/description/
class Solution {
public:
       int min(int a,int b)
        {
            if(a<b)
                return a;
            else
                return b;
        }
    string longestCommonPrefix(vector<string>& strs)
    {
        int n=strs.size();
        int m=INT_MAX;
        string str;
        for(int i=0;i<n;i++)
        {
            m=min( m,(strs[i]).size() );
            
        }
        for(int i=0;i<m;i++)
        {
           bool same=true;
           char ch=strs[0][i];
          
           for(int j=1;j<n;j++)
           {    
                if(strs[j][i]!=ch)
                {
                    same=false;
                    break;
                }
           }
           if(same==true)
           {
              str+=ch; 
           }
           else
            break;
        }
        
        return str;
        
        
        
    }
        
};