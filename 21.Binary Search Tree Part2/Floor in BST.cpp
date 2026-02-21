// https://www.geeksforgeeks.org/problems/floor-in-bst/1
class Solution {
  public:
    void helper(int& ans,Node* root, int x)
    {
         if(root==NULL) return;
         if(root->data<=x)
         {
             ans=max(ans,root->data);
             helper(ans,root->right,x);
         }
         else
         {
              helper(ans,root->left,x);
         }
       
    }
    int floor(Node* root, int x) 
    {
        int ans=-1;
        helper(ans,root, x);
        return ans;
    }
};