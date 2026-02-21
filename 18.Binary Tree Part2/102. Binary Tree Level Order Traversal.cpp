
// https://leetcode.com/problems/binary-tree-level-order-traversal/



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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>>ans;

        queue<TreeNode*>q;

        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            vector<int>temp;
            while(len--)
            {
                 TreeNode* x=q.front();
                 q.pop();
                 temp.push_back(x->val);
                 if(x->left!=NULL)
                 {
                    q.push(x->left);
                 }
                 if(x->right!=NULL)
                 {
                    q.push(x->right);
                 }
            }
            ans.push_back(temp);
        }
        return ans;

    }
};