// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
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
    stack<TreeNode*>inorder;
    stack<TreeNode*>postorder;
    void initializer(TreeNode* root)
    {
        inorder.push(root);
        postorder.push(root);
        while(inorder.top()->left!=NULL)
        {
            inorder.push(inorder.top()->left);
        }
        while(postorder.top()->right!=NULL)
        {
            postorder.push(postorder.top()->right);
        }
    }
    bool hasNextInLeft()
    {
        return inorder.size()>0;
    }
    bool hasPrevInRight()
    {
        return postorder.size()>0;
    }
    TreeNode* nextInLeft()
    {
        TreeNode* x=inorder.top();
        TreeNode* a=x;
        inorder.pop();
        if(x->right!=NULL)
        {
            inorder.push(x->right);
            while(inorder.top()->left!=NULL)
            {
                inorder.push(inorder.top()->left);
            }
        }
        return a;
    }
    TreeNode* prevInRight()
    {
        TreeNode* x=postorder.top();
        TreeNode* a=x;
        postorder.pop();
        if(x->left!=NULL)
        {
            postorder.push(x->left);
            while(postorder.top()->right!=NULL)
            {
                postorder.push(postorder.top()->right);
            }
        }
        return a;
    }
    bool findTarget(TreeNode* root, int k) 
    {
        initializer(root);

        if(inorder.top()==postorder.top()) return false;
         TreeNode* a;
           TreeNode* b;
           if( hasNextInLeft() )
           {
              a=nextInLeft();
           }
           else
           {
             return false;
           }
           if(hasPrevInRight())
           {
             b=prevInRight();
           }
           else
           {
             return false;
           }
        while(1)
        {
           if(a->val+b->val==k)
           {
               if(a==b) return false;
               return true;
           }
           else if(a->val+b->val<k)
           {
              if(!hasNextInLeft()) return false;
              a=nextInLeft();
           }
           else
           {
              if(!hasPrevInRight()) return false;
              b=prevInRight();
           }
        }
        return false;
    }
};