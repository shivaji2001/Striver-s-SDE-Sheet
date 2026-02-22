// https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1
class Node{
    public:
    Node* children[26];
    
    bool doesContain(char ch)
    {
        return children[ch-'a'];
    }
    void put(char ch,Node* node)
    {
        children[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return children[ch-'a'];
    }
    
};
class Solution {
  public:
    int countSubs(string& s) {
       int n=s.size();
       Node* root=new Node();
       int count=0;
       for(int i=0;i<n;i++)
       {
           Node* curr=root;
           for(int j=i;j<n;j++)
           {
               if(!curr->doesContain(s[j]))
               {
                   count++;
                   curr->put(s[j],new Node());
                   
               }
               curr=curr->get(s[j]);
           }
       }
       return count;
        
    }
};