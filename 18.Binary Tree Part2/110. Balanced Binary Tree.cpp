// https://leetcode.com/problems/balanced-binary-tree/description/
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
    bool isBlncd=true;
    int helper(TreeNode* root)
    {
        if(root==NULL) return 0;
        if(isBlncd==false) return -1;
        int left=helper(root->left);
        int right=helper(root->right);
        if(abs(left-right)>1)
        {
            isBlncd=false;
            return -1;
        }
        return max(left,right)+1;

    }
    bool isBalanced(TreeNode* root) 
    {
        helper(root);
        return isBlncd;
    }
};