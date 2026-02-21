// https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool helper(Node* r1, Node* r2)
    {
        if(r1==NULL and r2==NULL) return true ;
        if(r1==NULL and r2!=NULL) return false;
        if(r1!=NULL and r2==NULL) return false;
        
        if(r1->data!=r2->data) return false;
        bool left=helper(r1->left, r2->left);
        bool right=helper(r1->right, r2->right);
        
        if(left==false or right==false) return false;
        return true;
    }
    bool isIdentical(Node* r1, Node* r2) 
    {
        return helper(r1, r2);
        
    }
};