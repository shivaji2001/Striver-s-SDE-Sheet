// https://www.geeksforgeeks.org/problems/preorder-traversal/1
/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> preOrder(Node* root) 
    {
        Node* curr=root;
        
        vector<int>ans;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else
            {
                Node* prev=curr->left;
                while(prev->right!=NULL and prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    ans.push_back(curr->data);
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans; 
        
        
    }
};