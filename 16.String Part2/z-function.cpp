// https://www.geeksforgeeks.org/problems/search-pattern0205/1
class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
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
                   ans.push_back(i-n+1);
           }
           
        //   txtHash= (     ((txtHash-(txt[i-n+1]-'a'+1)*power+modu)*base)%modu  +txt[i+1]-'a'+1 )%modu;
        txtHash = ( ((txtHash - (txt[i - n + 1] - 'a' + 1) * power % modu + modu) % modu * base) % modu 
            + (txt[i + 1] - 'a' + 1) ) % modu;
           
       }
       if(patHash==txtHash)
           {
              if(pat==txt.substr(m-n,n))
                   ans.push_back(m-n);
           }
       return ans;
        
    }
};