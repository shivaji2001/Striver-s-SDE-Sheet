// https://leetcode.com/problems/binary-search-tree-iterator/description/
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
class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        st.push(root);
        while(root->left!=NULL)
        {
            st.push(root->left);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* x=st.top();
        int a=x->val;
        st.pop();
        if(x->right!=NULL)
        {
            st.push(x->right);
            x=x->right;
            while(x->left!=NULL)
            {
                st.push(x->left);
                x=x->left;
            }
        }
        return a;

    }
    
    bool hasNext() {
        return st.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */