// R
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
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
    bool found=false;
    TreeNode* ans=NULL;
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
         if(root==NULL) return false;
         
         bool presentInLeft=helper(root->left,p,q);
         bool presentInRight=helper(root->right,p,q);
         if(root==p and presentInLeft==true and found==false )
         {
            found=true;
            ans=root;
         }
         else if(root==p and presentInRight==true and found==false)
         {
             found=true;
             ans=root;
         }
         else if(root==q and presentInLeft==true and found==false)
         {
             found=true;
             ans=root;
         }
         else if(root==q and presentInRight==true and found==false)
         {
             found=true;
             ans=root;
         }
         else if(presentInLeft==true and presentInRight==true and found==false)
         {
             found=true;
             ans=root;
         }
        
         if(presentInLeft==true or presentInRight==true or  root==p or root==q )
         {
            return true;
         }
         return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};