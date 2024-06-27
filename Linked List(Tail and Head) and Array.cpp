#include <bits/stdc++.h>
using namespace std;

class Array{
    public:;
    int *data;
    int size;
    Array(int n=0){
        this -> data=new int[n]{};
        this->size=n;
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
        return NULL;
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

void insertAtTail(Node* &tail,int t){
    Node* temp= new Node(t);
    tail->next=temp;
    tail=temp;
};

void insertAt_P_Position(Node* &head,Node* &tail,int p,int t){
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
    if(v->next==NULL){
        tail=v;
    }
};

void print(Node* &head){
    Node* temp=head;
    cout<<temp->data<<" ";
    while(temp->next!=NULL){
        temp=temp->next;
        cout<<temp->data<<" ";
    }
};

void delete_at_P(Node* &head,Node *&tail,int p){
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
            if(d->next!=NULL){
                d->next=NULL;
                delete d;
            }
            else{
                tail=temp;
                delete d;
            }
        }
        temp=temp->next;
    }

};

void towerOfHanoi(int n, Array* &fromRod, Array* &toRod, Array* &auxRod) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << fromRod << " to rod " << toRod << endl;
        push(toRod,pop(fromRod));
        return;
    }
    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    cout << "Move disk " << n << " from rod " << fromRod << " to rod " << toRod << endl;
    push(toRod,pop(fromRod));
    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main(){

//Linked List Operations
Node *LL=new Node(10);
Node* head=LL;
Node* tail=LL;
insertAtTail(tail,20);
insertAtHead(head,1);
insertAt_P_Position(head,tail,3,30);
print(head);
cout<<endl;
delete_at_P(head,tail,2);
print(head);

//Array Operations
cout<<endl<<endl;
Array* sa=new Array();
push(sa,2);
push(sa,3);
cout<<pop(sa)<<endl;
cout<<pop(sa)<<endl;
cout<<pop(sa)<<endl;

//Tower of Hanoi
int n;
cout<<"Enter the no. of disks : "<<endl;
cin>>n;
Array* a= new Array();
Array* b= new Array();
Array* c= new Array();

for(int i=1;i<=n;i++){
    push(a,i);
}

towerOfHanoi(n,a,b,c);
cout<<"Secondary Stack"<<endl;
for(int i=0;i<n;i++){
   cout<<b->data[i]<<endl;
}

//Parenthesis matching

Node *par=new Node(0);
head=par;
tail=par;

string x;
cout<<"Enter an expression";
cin>>x;
int n1=1;
for(int i=0;i<size(x);i++){
    if(x[i]=='('){
        insertAtTail(tail,1);
        n1++;
    }
    else if(x[i]=='['){
        insertAtTail(tail,2);
        n1++;
    }
    else if(x[i]=='{'){
        insertAtTail(tail,3);
        n1++;
    }
    else if(x[i]==')'){
        if(tail->data==1){
            delete_at_P(head,tail,n);
            n1--;
        }
        else{
            cout<<"The expression is not correct"<<endl;
            break;
        }
    }
    else if(x[i]==']'){
        if(tail->data==2){
            delete_at_P(head,tail,n);
            n1--;
        }
        else{
            cout<<"The expression is not correct"<<endl;
            break;
        }
    }
    else if(x[i]=='}'){
        if(tail->data==3){
            delete_at_P(head,tail,n);
            n1--;
        }
        else{
            cout<<"The expression is not correct"<<endl;
            break;
        }
    }
};
if(n1!=1){
    cout<<"The Expression is'nt correct"<<endl;
}
else{
    cout<<"The Expression is correct"<<endl;
}


};

