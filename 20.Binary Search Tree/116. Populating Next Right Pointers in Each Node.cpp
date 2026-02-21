
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL) return NULL;
        root->next=NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<Node*>temp;
            while(sz--)
            {
                Node* p=q.front();
                q.pop();
                temp.push_back(p);
                if(p->left!=NULL)
                {
                    q.push(p->left);

                }
                if(p->right!=NULL)
                {
                    q.push(p->right);
                }
            }
            for(int i=0;i<temp.size()-1;i++)
            {
                if(i==temp.size()-1)
                {
                    temp[i]->next=NULL;
                    continue;
                }
                temp[i]->next=temp[i+1];
            }
        }
        return root;
        
    }
};