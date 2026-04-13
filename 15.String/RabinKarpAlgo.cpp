// https://leetcode.com/problems/repeated-string-match/description/

class Solution {
public:
    bool search(string pat, string txt) {
       int n=pat.size();
       int m=txt.size();
       long patHash=0;
       long txtHash=0;
       int modu=1000000007;
       vector<int>ans;
       long long base=31;
       for(int i=0;i<n;i++)
       {
           patHash=( (patHash*base) +  (pat[i]-'a'+1)  )%modu;
           txtHash=( (txtHash*base) +  (txt[i]-'a'+1)  )%modu;
       }
     
       long long power = 1;
for(int i = 0; i < n - 1; i++) {
    power = (power * base) % modu;
}
       
       for(int i=n-1;i<=m-2;i++)
       {
           if(patHash==txtHash)
           {
               if(pat==txt.substr(i-n+1,n))
                   return true;
           }
           
        //   txtHash= (     ((txtHash-(txt[i-n+1]-'a'+1)*power+modu)*base)%modu  +txt[i+1]-'a'+1 )%modu;
        txtHash = ( ((txtHash - (txt[i - n + 1] - 'a' + 1) * power % modu + modu) % modu * base) % modu 
            + (txt[i + 1] - 'a' + 1) ) % modu;
           
       }
       if(patHash==txtHash)
           {
              if(pat==txt.substr(m-n,n))
                   return true;
           }
       return false;
        
    }
    int repeatedStringMatch(string a, string b) {
        string as="";
        string bs="";
        int ans=0;
        while(as.size()<b.size())
        {
            as+=a;
            ans++;
        }
        if(search( b,as) )
        {
            return ans;
        }
        else if(search( b,as+a))
        {
            return ans+1;
        }
        return -1;
    }
};