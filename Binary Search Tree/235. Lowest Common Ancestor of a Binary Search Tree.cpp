// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL) return NULL;
        TreeNode* left=helper(root->left, p, q);
        TreeNode* right=helper(root->right, p, q);
        if(left==NULL and right==NULL)
        {
            if(root==p or root==q) return root;
            else return NULL;
        }
        else if(left==NULL and right!=NULL)
        {
            if(right==p) 
               {
                 if(root==q) return root;
                 return right;
               }
               else
               {
                  if(root==p) return root;
                  return right;
               }
            
        }
        else if(left!=NULL and right==NULL)
        {
               if(left==p) 
               {
                 if(root==q) return root;
                 return left;
               }
               else
               {
                  if(root==p) return root;
                  return left;
               }
            
        }
        else
        {
            if( (left==p and right==q ) or (left==q and right==p) ) return root;
            return NULL;
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root, p, q);
    }
};