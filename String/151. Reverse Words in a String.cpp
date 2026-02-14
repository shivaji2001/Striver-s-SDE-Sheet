// https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) 
    {
         reverse(s.begin(),s.end());
        
         int n=s.size();
        string temp="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            continue;
            else
            {
                int start=i;
                int end=i;
                string temp2="";
                temp2.push_back(s[start]);
                while(end+1<n and s[end+1]!=' ')
                {
                    end++;
                    temp2.push_back(s[end]);
                }
                reverse(temp2.begin(),temp2.end());
                temp2.push_back(' ');

                temp+=temp2;
                i=end;
                
            }
           
        }
        temp.pop_back();
        
        return temp;
        
    }
};