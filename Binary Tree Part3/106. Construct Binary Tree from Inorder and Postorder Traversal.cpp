//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    int findIndexInInorder(int val,vector<int>&inorder)
    {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* helper(int i,int j,int x,int y,vector<int>& inorder, vector<int>& postorder)
    {
        if(i==j)
        {
            TreeNode* x=new TreeNode(inorder[i]);
            return x;
        }
        if(i>j) return NULL;
        int a=postorder[y];
        TreeNode* root=new TreeNode(a);
        int index=findIndexInInorder(a,inorder);
        int lenCommon=index-i;
        root->left=helper(i,index-1,x,x+lenCommon-1, inorder, postorder);
        root->right=helper(index+1, j,x+lenCommon, x+lenCommon+j-index-1,inorder,  postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return helper(0, n-1, 0, n-1, inorder,  postorder);
    }
};