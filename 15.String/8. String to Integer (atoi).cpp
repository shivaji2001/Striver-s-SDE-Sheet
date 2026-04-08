// https://leetcode.com/problems/string-to-integer-atoi/description/
class Solution {
public:
    int myAtoi(string s) 
    {
        
        bool negative=false;
        bool positive=false;
        int n=s.size();
        long long ans=0;
        bool limitReached=false;
        bool anyNumberOccured=false;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='-')
            {
                if(negative)
                {
                    if(anyNumberOccured)
                    {
                        if(negative) ans=-1*ans;
                        return ans;
                    }
                    else
                    {
                        return 0;
                    }
                }
                if(anyNumberOccured)
                {
                    if(negative) ans=-1*ans;
                    return ans;
                }
                negative=true;
                continue;
            }
            else if(s[i]=='+')
            {
                if(positive)
                {
                    if(anyNumberOccured)
                    {
                        if(negative) ans=-1*ans;
                        return ans;
                    }
                    else
                    {
                        return 0;
                    }
                }
                if(anyNumberOccured )
                {

                    if(negative) ans=-1*ans;
                    return ans;
                }
                positive=true;
                continue;
            }
            int a=s[i]-'0';
            if(s[i]==' ')
            {
                if(anyNumberOccured or positive or negative)
                {
                     if(negative) ans=-1*ans;
                      return ans;
                }
                continue;
            }
            else if(a<=9 and a>=0)
            {
               anyNumberOccured=true;
               if( ans*10+a>INT_MAX)
               {
                  limitReached=true;
                  break;
               }
               ans=ans*10+a;
            }
            else
            {
                if(negative) ans=-1*ans;
                return ans;
            }
        }
        if(limitReached==true)
        {
            
            if(negative) return INT_MIN;
            else return INT_MAX;
        }
        if(positive and negative)
        {
            return 0;
        }
        cout<<"Block a"<<endl;
        if(negative)
        ans=-1*ans;
        return ans;
    }
};