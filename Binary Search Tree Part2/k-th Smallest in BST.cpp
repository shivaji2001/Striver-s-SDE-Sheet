// https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node *root, int k,int& count,int& ans)
    {
        if(root==NULL) return ;
       
        if(ans!=-1) return;
        inorder(root->left, k, count,ans);
        count++;
        if(count==k)
        {
            ans=root->data;
            return;
        }
        inorder(root->right, k, count,ans);
    }
    int kthSmallest(Node *root, int k) {
        int ans=-1;
        int count=0;
        inorder(root, k,count,ans);
        return ans;
    }
};