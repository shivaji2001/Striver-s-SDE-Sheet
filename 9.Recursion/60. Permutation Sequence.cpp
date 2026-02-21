// https://leetcode.com/problems/permutation-sequence/description/


class Solution {
public:
    
    string getPermutation(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
          v.push_back(i);
        }
        int fact=1;
        for(int i=1;i<=n-1;i++)
        {
            fact=fact*i;
        }
        k--;
        vector<int>ans;
        int x=n-1;
        while(v.size()>1)
        {
            int index=k/fact;
            ans.push_back(v[index]);
            v.erase(v.begin()+index);
            k=k%fact;
            fact=fact/x;
            x--;

        }
        ans.push_back(v[0]);
        string fans="";
        for(int a:ans)
        {
            fans+=to_string(a);
            
        }
        return fans;


        
    }

};