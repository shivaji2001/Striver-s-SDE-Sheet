/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node *flatten(Node *root) {
        Node* temp=root;
        while(root!=NULL)
        {
            if(root->bottom==NULL)
            {
                root=root->next;
                
            }
            else if(root->next==NULL)
            {
                root->next=root->bottom;
                root->bottom=NULL;
            }
            else if(root->bottom!=NULL and root->next!=NULL)
            {
                if(root->bottom->data<root->next->data)
                {
                    root->bottom->next=root->next;
                    root->next=root->bottom;
                    root->bottom=NULL;
                    root=root->next;
                }
                else
                {
                    Node* temp=root;
                    while(root->next!=NULL and root->next->data<temp->bottom->data)
                    {
                        root=root->next;
                        
                        
                    }
                    temp->bottom->next=root->next;
                    root->next=temp->bottom;
                    temp->bottom=NULL;
                    root=temp;
                }
            }
        }
        Node* temp2=temp;
        while(temp2!=NULL)
        {
            temp2->bottom=temp2->next;
            temp2->next=NULL;
            temp2=temp2->bottom;
        }
        return temp;
         
    }
};