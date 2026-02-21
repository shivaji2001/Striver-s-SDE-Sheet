//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    int findIndex(int val,vector<int>& inorder)
    {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
           if(inorder[i]==val) return i;
        }
        return -1;
    }
    TreeNode* helper(int i,int j,int& x,vector<int>& preorder, vector<int>& inorder,int n)
    {
       if(i==j)
       {
        TreeNode* temp=new TreeNode(preorder[x]);
        x++;
        return temp;
       }
       if(i>j) return NULL;
       TreeNode* root=new TreeNode(preorder[x]);
       int index=findIndex(preorder[x],inorder);
       x++;
       
       root->left=helper( i, index-1, x, preorder,  inorder, n);
       root->right=helper( index+1, j, x, preorder,  inorder, n);

       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        int x=0;
        return helper(0, n-1, x,preorder, inorder, n);

    }
};