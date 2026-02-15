// https://www.geeksforgeeks.org/problems/inorder-traversal/1
/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        Node* temp=root;
        vector<int>ans;
        while(temp!=NULL)
        {
            if(temp->left==NULL)
            {
                ans.push_back(temp->data);
                temp=temp->right;
            }
            else
            {
                Node* ip=temp->left;
                while(ip->right!=NULL and ip->right!=temp)
                {
                    ip=ip->right;
                }
                if(ip->right==NULL)
                {
                    ip->right=temp;
                    temp=temp->left; 
                }
                else
                {
                    ans.push_back(temp->data);
                    ip->right=NULL;
                    temp=temp->right;
                }
                
            }
        }
        return ans;
    }
};