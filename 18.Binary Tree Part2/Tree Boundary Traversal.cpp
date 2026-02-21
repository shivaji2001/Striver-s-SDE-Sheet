// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leftView(Node *root,vector<int>&ans)
    {
        Node* curr=root->left;
        while(curr!=NULL)
        {
            if(curr->left==NULL and curr->right==NULL)
            {
                break;
            }
            ans.push_back(curr->data);
            if(curr->left!=NULL)
            {
                curr=curr->left;
            }
            else
            {
                curr=curr->right;
            }
            
        }
    }
    void leafNodes(Node *root,vector<int>&ans)
    {
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL)
        {
            ans.push_back(root->data);
        }
        leafNodes(root->left,ans);
        leafNodes(root->right,ans);
    }
    vector<int> rightNodes(Node *root)
    {
        vector<int>temp;
        if(root==NULL) return temp;
        
        Node* curr=root->right;
        while(curr!=NULL)
        {
            if(curr->left==NULL and curr->right==NULL)
            {
                break;
            }
            temp.push_back(curr->data);
            if(curr->right!=NULL)
            {
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    vector<int> boundaryTraversal(Node *root) {
       vector<int>ans;
       if(root==NULL) return ans;
       if(root->left==NULL and root->right==NULL)
       {
           ans.push_back(root->data);
           return ans;
       }
       ans.push_back(root->data);
       leftView(root,ans);
       leafNodes(root,ans);
       vector<int>rt=rightNodes(root);
       for(int a:rt)
       {
           ans.push_back(a);
       }
       return ans;
       
        
    }
};