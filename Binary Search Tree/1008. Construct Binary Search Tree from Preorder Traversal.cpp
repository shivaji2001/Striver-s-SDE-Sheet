// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(int x,TreeNode* &root)
    {
        if(root==NULL)
        {
             root=new TreeNode(x);
             return;
        }
        if(x>root->val)
        {
            helper(x,root->right);
        }
        else
        {
            helper(x,root->left);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        int n=preorder.size();
        TreeNode* ans=NULL;
        // ans=new TreeNode(5);
        for(int i=0;i<n;i++)
        {
            helper(preorder[i],ans);
        }
        return ans;


        
    }
};