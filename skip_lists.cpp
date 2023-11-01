#include <iostream>
#include <math.h>
using namespace std;

class node{
    public:
    node *next;
    int n;
    node(){
        this->n=0;
        this->next=NULL;
    }
};

class linked{
    public:
    node* list;
    int row;
    linked(){
        this->list=new node[0];
        this->row=0;
    }
    void insert(node d){
        node* t=new node[row+1];
        for(int i=0;i<row;i++){
            t[i]=list[i];
        }
        t[row]=d;
        this->row=row+1;
    }

};

class array{
    public:
    linked *arr;
    int p;
    int col;

    array(){
        this->arr=new linked[1];
        this->p=0;
        this->col=1;
    }

    void resize(){
        linked* t=new linked[1+col];
        for(int i=0;i<col;i++){
            t[i]=arr[i];
        }
        delete arr;
        this->arr=t;
        this->col=1+col;
    }

    void insert(int n){
        if(p<col){
            node temp;
            temp.n=n;
            arr[p].insert(temp);
            p++;
        }
        else{
            this->resize();
            this->insert(n);
        }
    }

    void sort(){
        for(int i=1;i<p;i++){
            int j=i;
            while(j>0){
                if(arr[j].list->n<arr[j-1].list->n){
                    linked t=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=t;
                    j--;
                }
                else{
                    break;
                }
            }
        }
    }

};

array* build(array* root){
    root=new array();
    while (true){
        int n;
        cout<<"Enter the element to be inserted: ";
        cin>>n;
        if(n!=0){
            root->insert(n);
        }
        else{
            break;
        }
    }

    root->sort();
    
    int n=root->p/2;
    int c=n/2;
    for(int i=1;i<log2(root->p);i++){
        root->arr[n].insert(root->arr[n].list[0]);
        for(int j=2;j<c;j=j+2){
            root->arr[n+j].insert(root->arr[n+j].list[0]);
            root->arr[n-j].insert(root->arr[n-j].list[0]);
        }
        for(int k=n-c+2;k<n+c-4;k=k+2){
            root->arr[k].list[i].next=&root->arr[k+2].list[i];
        }
        c/=2;
    }    
    return root;
}

int main(){
    array* root;
    root=build(root);
}
