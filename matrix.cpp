#include <iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node(){
        this->data=0;
        this->next=NULL;
    }
};

class array{
    public:
    node* l;
    array(int n){
        this-> l=new node[n];
    }
};

int access(array* a,int i,int j){
    node* temp=&a->l[j-1];
    for(int l=1;l<i;l++){
        temp=temp->next;
    }
    return temp->data;
}

int main(){
    int n;
    cin>>n;
    array* matrix=new array(n);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            node* temp=&matrix->l[j];
            for(int l=0;l<i;l++){
                temp=temp->next;
            }
            temp->next=new node;
            cin>>temp->data;
        }
    }
    
    int val1=0;
    int val2=0;
    for(int i=1;i<=n;i++){
            val1=val1+access(matrix,i,i);
            val2=val2+access(matrix,i,n-i+1);
    }
    cout<<abs(val1-val2);
}