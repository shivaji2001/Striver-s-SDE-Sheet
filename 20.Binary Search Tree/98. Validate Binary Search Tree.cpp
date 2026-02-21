// https://leetcode.com/problems/validate-binary-search-tree/description/
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
    bool helper(TreeNode* root,long long mini,long long maxi)
    {
        if(root==NULL) return true;
        if(  !(root->val<maxi and root->val>mini)  ) return false;
        if(  helper(root->right,max((long long)root->val,mini),maxi)==false ) return false;
        if(  helper(root->left,mini,min((long long)root->val,maxi))==false ) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long mini=LLONG_MIN;
        long long maxi=LLONG_MAX;
        
        return helper(root,mini,maxi);
    }
};