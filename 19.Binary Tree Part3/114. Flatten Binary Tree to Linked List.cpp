//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL)
         return;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->right==NULL and curr->left==NULL) break;
            if(curr->right==NULL) 
            {
                curr=curr->left;
                continue;
            }
            if(curr->left==NULL)
            {
                curr->left=curr->right;
                curr->right=NULL;
                curr=curr->left;
                continue;
            }
            TreeNode* temp=curr->left;
            while(temp->right!=NULL)
            {
                temp=temp->right;
            }
            temp->right=curr->right;
            curr->right=NULL;
            curr=curr->left;

        }
        TreeNode* p=root;
        while(p!=NULL)
        {
            swap(p->left,p->right);
            p=p->right;
        }
        

    }
};