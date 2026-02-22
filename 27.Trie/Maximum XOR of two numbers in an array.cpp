//https://www.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1

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
        return children[x-'0']!=NULL;
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
class Solution {
  public:
    int maxXor(vector<int> &arr) 
    {
        int n=arr.size();
        int maxNoOfBits=0;
        for(int a:arr)
        {
            maxNoOfBits=max(maxNoOfBits,(int)log2(a)+1);
        }
        TrieNode* root=new TrieNode();
        for(int i=0;i<arr.size();i++)
        {
            string bits=getBits(arr[i],maxNoOfBits);
            TrieNode* curr=root;
            for(int i=0;i<maxNoOfBits;i++)
            {
                if(!curr->doesContain(bits[i]))
                {
                    curr->put(bits[i],new TrieNode());
                }
                curr=curr->get(bits[i]);
            }
            curr->isEnd=true;
        }
        int maxi=0;
        for(int i=0;i<arr.size();i++)
        {
            string bits=getBits(arr[i],maxNoOfBits);
            TrieNode* curr=root;
            int no=0;
            for(int i=0;i<maxNoOfBits;i++)
            {
                char ch=bits[i];
                if(ch=='0')
                {
                    if(curr->doesContain('1'))
                    {
                        no+= 1<<(maxNoOfBits-i-1);
                        curr=curr->get('1');
                    }
                    else
                    {
                        curr=curr->get('0');
                    }
                }
                else
                {
                    if(curr->doesContain('0'))
                    {
                        no+= 1<<(maxNoOfBits-i-1);
                        curr=curr->get('0');
                    }
                    else
                    {
                        
                        curr=curr->get('1');
                    }
                }
            }
            maxi=max(maxi,no);
        }
        
        return maxi;
        
        
    }
};