#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    bool isEndOfWord;
    Node* children[26];
    Node()
    {
       
        isEndOfWord=false;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++)
        {
            if(temp->children[word[i]-'a']==NULL)
            {
                 temp->children[word[i]-'a']=new Node();
            }
            temp=(temp->children)[word[i]-'a'];
        }
        temp->isEndOfWord=true;
    }
    
    bool search(string word) {
        int n=word.size();
        Node* temp=root;
        for(int i=0;i<n;i++)
        {
            if(temp->children[word[i]-'a']==NULL) return false;
            temp=(temp->children)[word[i]-'a'];
        }
        if(temp->isEndOfWord==false) return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        Node* temp=root;
        for(int i=0;i<n;i++)
        {
            if(temp->children[prefix[i]-'a']==NULL) return false;
            temp=temp->children[prefix[i]-'a'];
        }
        return true;
    }
};
class Solution {
public:
    bool doesSatisfy(string word, Trie* trie)
    {
        int n=word.size();
        Node* curr = trie->root;
        
        for(int i=0;i<n;i++)
        {
           if(curr->children[word[i]-'a']==NULL)
           {
             return false;
           }
           curr=curr->children[word[i]-'a'];
           if(curr->isEndOfWord==false)
           {
            return false;
           }

        }
        return true;
    }
    static bool comp(const string& s1,const string& s2)
    {
        if(s1.size()!=s2.size())
        {
            return s1.size()<s2.size();
        }
        return s1<s2;
    }
    string completeString(vector<string>& nums) {
        Trie* trieObj=new Trie();
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
           trieObj->insert(nums[i]);
        }
        sort(nums.begin(),nums.end(),comp);
        int maxSize=-1;
        vector<string>ans;
        for (int i = n - 1; i >= 0; i--)
        {
            if(nums[i].size()>maxSize)
            {
                cout<<"nums[i].size()"<<nums[i].size()<<endl;
                cout<<"maxsize is "<<maxSize<<endl;
                cout<<"breaking at index "<<i<<endl;
                 break;
            }
            
            if(doesSatisfy(nums[i], trieObj) )
            {
                ans.push_back(nums[i]) ;
            } 
        }
        
        if(ans.size()==0)
        {
            return "None";
        }
        return ans[0];
    }
};
int main()
{
    Solution sol;

   
    vector<string> nums1 = {"n", "ni", "nin", "ninj", "ninja", "nil"};
    cout << "Output: " << sol.completeString(nums1) << endl;
    
    vector<string> nums2 = {"ninja", "night", "nil"};
    cout << "Output: " << sol.completeString(nums2) << endl;
    
    vector<string> nums3 = {"s", "sh", "shi","shiv","shiva","shivan","shivans","shivansh","s","h","i"};
    cout << "Output: " << sol.completeString(nums3) << endl;
    

    return 0;
}

