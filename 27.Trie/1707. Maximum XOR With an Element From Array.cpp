//https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

class TrieNode{
    public:
    TrieNode* children[2];
    bool isEnd;
    TrieNode()
    {
        children[0]=NULL;
        children[1]=NULL;
        isEnd=false;
    }
    bool doesContain(char x)
    {
        return children[x-'0'];
    }
    void put(char x,TrieNode* node)
    {
        children[x-'0']=node;
    }
    TrieNode* get(char x)
    {
        return children[x-'0'];
    }
};
class Solution {
public:
    static bool comp(pair<int,pair<int,int>>&p1,pair<int,pair<int,int>>&p2)
    {
        return p1.second.second<p2.second.second;
    }
    string getBits(int a,int total)
    {
        string temp="";
        for(int i=total-1;i>=0;i--)
        {
            if(   a&(1<<i)   )
            temp.push_back('1');
            else
            temp.push_back('0');
        }
        return temp;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
         sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>>que2;
        for(int i=0;i<queries.size();i++)
        {
            que2.push_back({i,{queries[i][0],queries[i][1]}});
        }
        sort(que2.begin(),que2.end(),comp);
        int maxNoOfBits=32;
        vector<int>ans(que2.size(),-1);
        int maxi=-1;
        int j=0;
       
        TrieNode* root=new TrieNode();
        
        for(int i=0;i<que2.size();i++)
        {
            
            int index=que2[i].first;
            int x=que2[i].second.first;
            int maxNo=que2[i].second.second;
            
            maxi=max(maxi,maxNo);
            
            while(j<nums.size() and nums[j]<=maxi)
            {
                string bits=getBits(nums[j],maxNoOfBits);
                TrieNode* curr=root;
                for(int k=0;k<maxNoOfBits;k++)
                {
                    if(!curr->doesContain(bits[k]))
                    {
                        curr->put(bits[k],new TrieNode());
                    }
                    curr=curr->get(bits[k]);
                }
                curr->isEnd=true;
                
                j++;
               
            }
           
            string curNoBits=getBits(x,maxNoOfBits);
            
            int no=0;
            TrieNode* tempPointer=root;
            bool ansFound=true;
            for(int l=0;l<maxNoOfBits;l++)
            {
                char ch=curNoBits[l];
                if(ch=='0')
                {
                    if(tempPointer->doesContain('1'))
                    {
                        
                        no+= 1<<(maxNoOfBits-l-1);
                        tempPointer=tempPointer->get('1');
                    }
                    else if(tempPointer->doesContain('0'))
                    {
                       
                        tempPointer=tempPointer->get('0');
                    }
                    else
                    {
                       
                        ans[index]=-1;
                        ansFound=false;
                        break;
                    }
                }
                else
                {
                    if(tempPointer->doesContain('0'))
                    {
                        
                        no+= 1<<(maxNoOfBits-l-1);
                        tempPointer=tempPointer->get('0');
                    }
                    else if(tempPointer->doesContain('1'))
                    {
                        
                        tempPointer=tempPointer->get('1');
                    }
                    else
                    {
                       
                        ans[index]=-1;
                        ansFound=false;
                        break;
                    }
                }
            }
            if(ansFound==true)
            ans[index]=no;
         }

        
        return ans;
    }
};