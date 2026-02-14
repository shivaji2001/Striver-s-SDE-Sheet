// https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    
    // void helper(int depth,int curr,Node *root,unordered_map<int,int>&mp)
    // {
    //     if(root==NULL) return;
    //     if(curr<left)
    //     {
    //         ans.push_back(root->data);
    //         left=curr;
    //     }
    //     helper(curr-1,root->left,ans);
    //     helper(curr+1,root->right,ans);
    // }
    vector<int> leftView(Node *root) {
        
        queue<Node *>q;
        q.push(root);
        int depth=0;
        vector<int>ans;
        while(!q.empty())
        {
            
            int x=q.size();
            depth++;
            while(x--)
            {
               
                Node* x=q.front();
                q.pop();
                if(ans.size()<depth)
                {
                    ans.push_back(x->data);
                }
                // cout<<x->data<<" ";
                if(x->left!=NULL)
                {
                    q.push(x->left);
                }
                if(x->right!=NULL)
                {
                    q.push(x->right);
                }
                
            }
            // cout<<endl;
        }
        return ans;
        
    }
};