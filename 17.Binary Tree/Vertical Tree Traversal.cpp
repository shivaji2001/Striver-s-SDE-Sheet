// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void helper(Node *root,map<int,vector<int>>&mp) 
    {
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            
            int x=q.size();
            
            while(x--)
            {
                auto it=q.front();
                mp[it.second].push_back(it.first->data);
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
    vector<vector<int>> verticalOrder(Node *root) {
       map<int,vector<int>>mp;
       helper(root,mp);
       vector<vector<int>>ans;
       for(auto it:mp)
       {
           ans.push_back(it.second);
       }
       return ans;
    }
};