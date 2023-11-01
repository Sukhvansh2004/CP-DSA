#include <iostream>
using namespace std;


class Node{

    public:;
    int data;
    Node *next;

    Node(int data){
        this -> data=data;
        this -> next=NULL;

    }
};

void insertAtHead(Node* &head,int t){
    Node* temp=new Node(t);
    temp->next=head;
    head=temp;

};


void insertAt_P_Position(Node* &head,int p,int t){
    if(p==1){
        insertAtHead(head,t);
        return;
    }
    int c=1;
    Node* temp=head;
    while(c<p-1){
        temp=temp->next;
        c++;
    }
    Node* v=new Node(t);
    v->next=temp->next;
    temp->next=v;
    
};

void print(Node* &head){
    Node* temp=head;
    cout<<temp->data<<" ";
    while(temp->next!=NULL){
        temp=temp->next;
        cout<<temp->data<<" ";
    }
};

void delete_at_P(Node* &head,int p){
    Node* temp=head;
    if(p==1){
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;

    }
    int c=1;
    while(c<p){
        c++;
        if(c==p){
            Node* d=temp->next;
            temp->next=d->next;
            d->next=NULL;
            delete d;
        }
        temp=temp->next;
    }

}

int main(){

//Linked List Operations
Node *LL=new Node(10);
Node* head=LL;
insertAtHead(head,1);
insertAt_P_Position(head,3,30);
print(head);
cout<<endl;
delete_at_P(head,2);
print(head);


}