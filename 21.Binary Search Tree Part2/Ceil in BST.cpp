// https://www.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
class Solution {
  public:
    void helper(int& ans,Node* root, int x)
    {
         if(root==NULL) return;
         if(root->data>=x)
         {
             ans=min(ans,root->data);
             helper(ans,root->left,x);
         }
         else
         {
              helper(ans,root->right,x);
         }
       
    }
    
    int findCeil(Node* root, int x) {
         int ans=INT_MAX;
        helper(ans,root, x);
        return ans==INT_MAX?-1:ans;
        
    }
};