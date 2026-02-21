// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
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
     
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
      

        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(!q.empty() )
        {
            int size=q.size();
            vector<int>temp;
            for(int i=1;i<=size;i++)
            {
                TreeNode* x=q.front();
                q.pop();
                temp.push_back(x->val);
                if(x->left!=NULL) 
                q.push(x->left);
                if(x->right!=NULL)
                q.push(x->right);
            }
            if(level==1)
            {
                level=2;
            }
            else
            {
                reverse(temp.begin(),temp.end());
                level=1;
            }
             ans.push_back(temp);
        }
        return ans;
    }
};