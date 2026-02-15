
// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,long long>>q;
        long long ans=INT_MIN;
        q.push({root,0});
        while(!q.empty())
        {
            long long sz=q.size();
            long long mini=INT_MAX;
            long long maxi=INT_MIN;
            for(int i=1;i<=sz;i++)
            {
                 auto x=q.front();
                 q.pop();
                 TreeNode* node=x.first;
                 long long ind=x.second;
                 mini=min(mini,ind);
                 maxi=max(maxi,ind);
                 if(i==1)
                 {
                    mini=ind;
                 }
                 if(i==sz)
                 {
                    maxi=ind;
                 }
                 if(node->left!=NULL)
                 {
                    q.push({node->left,2*(ind-mini)+1}); 
                 }
                 if(node->right!=NULL)
                 {
                    q.push({node->right,2*(ind-mini)+2}); 
                 }
            }
            ans=max(ans,maxi-mini+1);
            
        }
        return ans;
        
    }
};