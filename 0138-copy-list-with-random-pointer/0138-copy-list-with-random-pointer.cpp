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
    
    void insertcopyinbetween(Node *head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copy= new Node(temp->val);
            Node* nextelement=temp->next;
            copy->next=nextelement;
            temp->next=copy;
            temp=nextelement;       
        }
    }
    
    void connectrandompointer(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copynode=temp->next;
            if(temp->random){
                copynode->random=temp->random->next;
            }else{
                copynode->random=nullptr;
            }
            temp=temp->next->next;
        }
    }
    
    Node* getdeepcopy(Node* head){
        Node* temp=head;
        Node* dummynode= new Node(-1);
        Node* res=dummynode;
        while(temp!=NULL){
            res->next=temp->next;
            res=res->next;
            
            temp->next=temp->next->next;
            temp=temp->next;
            
        }
        return dummynode->next;
    }
    
    Node* copyRandomList(Node* head) {
        insertcopyinbetween(head);
     
        connectrandompointer(head);
        return getdeepcopy(head); 
    }
};