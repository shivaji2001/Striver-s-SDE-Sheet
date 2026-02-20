//https://leetcode.com/problems/symmetric-tree/description/

/*


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    pair<int,bool>helper(Node *root)
    {
        if(root==NULL) return {0,true};
        if(root->left==NULL and root->right==NULL) return {root->data,true};
        pair<int,bool> lt=helper(root->left);
        pair<int,bool> rt=helper(root->right);
        if(lt.second==false  or rt.second==false) return {root->data,false};
        if(lt.first+rt.first!=root->data) return {root->data,false};
        return {root->data,true};
    }
    bool isSumProperty(Node *root) {
        return helper(root).second;
        
    }
};