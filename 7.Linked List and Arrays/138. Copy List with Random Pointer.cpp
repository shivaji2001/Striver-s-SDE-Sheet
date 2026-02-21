/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node* temp=head;
       Node* newLL=NULL;
       Node* nit=NULL;
       unordered_map<Node*,Node*>um;
       while(head!=NULL){
         if(newLL==NULL)
         {
            newLL=new Node(head->val);
            um[head]=newLL;
            nit=newLL;
            head=head->next;
         }
         else
         {
            newLL->next=new Node(head->val);
            newLL=newLL->next;
            um[head]=newLL;
            head=head->next;
         }
       } 
       newLL=nit;
       cout<<"Printing map"<<endl;

       
       while(temp!=NULL)
       {
          newLL->random=um[temp->random];
          temp=temp->next;
          newLL=newLL->next;
       }
       return nit;

    }
};