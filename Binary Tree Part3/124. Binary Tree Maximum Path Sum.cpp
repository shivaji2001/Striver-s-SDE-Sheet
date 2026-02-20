//https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
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
    int helper(TreeNode* root,int& ans)
    {
        if(root==NULL) return 0;
        int left=helper(root->left,ans);
        int right=helper(root->right,ans);
        int a=root->val;
        int b=left+root->val;
        int c=right+root->val;
        int d=left+right+root->val;
        int maxi=max(  max(a,b),max(c,d)   );
        ans=max(ans,maxi); 
        return max(a,max(b,c));
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=INT_MIN;
        helper(root,ans);
        return ans;
    }
};