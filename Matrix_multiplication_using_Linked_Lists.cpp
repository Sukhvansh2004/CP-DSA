#include <iostream>
using namespace std;

class Array{
    public:
    int *data;
    int size;
    Array(int n=0){
        this -> data=new int[n]{};
        this->size=n;
    }

};

class Node{

    public:
    Array *data=new Array;
    Node *next;

    Node(){
        this -> next=NULL;

    }
};

void push(Array* &a,int i){
        Array* temp=new Array(a->size+1);
        for(int j=0;j<a->size;j++){
            temp->data[j]=a->data[j];         
        }
        temp->data[a->size]=i;
        a=temp;
    };

int pop(Array* &a){
    if(a->size==0){
        cout<<"UnderFlow Error"<<endl;
        return 0;
    }
    else{
        int t=a->data[--a->size];
        Array *temp=new Array(a->size);
        for(int j=0;j<a->size;j++){
            temp->data[j]=a->data[j];         
        }
        a=temp;
        return t;
    }
};

void insertAtTail(Node* &head){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* input=new Node();
    temp->next=input;

}

Node* access(Node* &head,int n){
    Node* temp=head;
    while(--n>0){
        temp=temp->next;
    }
    return temp;
}
int element(Array* &l,int i){
    return l->data[i-1];
}

Node* mul(Node*a,Node*b){
    Node* prod=new Node;
    for(int i=1;i<=3;i++){
        Node* temp=access(prod,i);
        for(int j=1;j<=3;j++){
            int sum=0;
            for(int l=1;l<=3;l++){
                sum=sum+element(access(a,l)->data,j)*element(access(b,i)->data,l);
            }
        push(temp->data,sum);
        }
        if(i<3){
            insertAtTail(prod);
        }
    }
    return prod;
}

void print(Node* &mat){
    for(int j=1;j<=3;j++){
        for(int i=1;i<=3;i++){
            cout<<element(access(mat,i)->data,j)<<" ";
        //    cout<<"check "<<i<<" and "<<j<<endl;
        }
        cout<<endl;
    }
}

int main(){
    Node* mat1=new Node;
    Node* mat2=new Node;
    Node* head1=mat1;
    Node* head2=mat2;

    cout<<endl<<"Entering data for Matrix 1"<<endl;
    for(int i=1;i<=3;i++){
        Node* col=access(head1,i);
        for(int j=1;j<=3;j++){
            int n;
            cout<<"Enter the data at "<<j<<" row and "<<i<<" column:";
            cin>>n;
            push(col->data,n);

        }
       if(i<3){
            insertAtTail(head1);

    }

    }

    cout<<endl<<"Entering data for Matrix 2"<<endl;
    for(int i=1;i<=3;i++){
        Node* col=access(head2,i);
        for(int j=1;j<=3;j++){
            int n;
            cout<<"Enter the data at "<<j<<" row and "<<i<<" column:";
            cin>>n;
            push(col->data,n);

        }
        if(i<3){
            insertAtTail(head2);
        }

    }

    Node* prod=mul(mat1,mat2);
    print(prod);

}