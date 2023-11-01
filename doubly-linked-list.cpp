#include <iostream>
using namespace std;

class Node{

    public:;
    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this -> data=data;
        this -> next=NULL;
        this -> prev=NULL;

    }
};

void insert(Node* &head,int t){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* element=new Node(t);
    temp->next=element;
    element->prev=temp;

}

void sort(Node* &head,int len){
    for(int j=1;j<len;j++){
        Node* temp=head;
        for(int i=0;i<j;i++){
                temp=temp->next;
            }
        while(j>0){
            if(temp->prev->data>temp->data){
                int t=temp->data;
                temp->data=temp->prev->data;
                temp->prev->data=t;
                temp=temp->prev;
                j--;
            }
            else{
                break;
            }
        }
    }
}

int main(){

    cout<<"Enter the starting element :";
    int x;
    cin>>x;
    Node* list=new Node(x);
    Node* head=list;
    int n;
    cout<<"Enter the no. of elements you want add more to enter in the list : ";
    cin>>n;
    for(int i=0;i<n;i++){
        int z;
        cin>>z;
        insert(head,z);
        cout<<endl;
    }
    sort(head,++n);
    cout<<"The sorted list is : "<<endl;
    Node*temp=head;
    for(int i=0;i<n;i++){
        cout<<temp->data<<" ";
        temp=temp->next;
    }


}