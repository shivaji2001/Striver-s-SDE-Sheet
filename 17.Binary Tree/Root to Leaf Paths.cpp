// https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1
/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void helper(Node* root,vector<int>&tempPath, vector<vector<int>>&ans)
    {
        if(root==NULL) return;
        tempPath.push_back(root->data);
        if(root->left==NULL and root->right==NULL)
        {
            ans.push_back(tempPath);
        }
        else
        {
            helper(root->left,tempPath,ans);   
            helper(root->right,tempPath,ans);
        }
        tempPath.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>>ans;
        vector<int>tempPath;
        helper(root,tempPath,ans);
        return ans;
    }
};