// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void helper(Node *root,map<int,int>&mp) {
        
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        
        while(!q.empty())
        {
            
            int x=q.size();
            
            while(x--)
            {
                auto it=q.front();
                mp[it.second]=it.first->data;
                q.pop();
                
                if(it.first->left!=NULL)
                {
                    q.push({it.first->left,it.second-1});
                }
                if(it.first->right!=NULL)
                {
                   q.push({it.first->right,it.second+1});
                }
                
            }
            
        }
        
    }
    
    vector<int> bottomView(Node *root) {
       map<int,int>mp;
       helper(root,mp);
       vector<int>ans;
       for(auto it:mp)
       {
           ans.push_back(it.second);
       }
       return ans;
    }
};