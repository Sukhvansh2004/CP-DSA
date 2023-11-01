#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    int i;
    int j;

    node(int arrindex,int indexinarr,int d){
        this->data=d;
        this->i=arrindex;
        this->j=indexinarr; 
    }
};
void heapify(node* arr[] , int i,int size){
    int smallest=i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=size && arr[left]->data<arr[smallest]->data){
        smallest=left;
    }
    if(right<=size && arr[right]->data<arr[smallest]->data){
        smallest=right;
    }

    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,smallest,size);
    }
}
class heap{
   public:
   node* arr[10000];
   int size;

   heap(){
    size=0;
    arr[0]=NULL;
   }

   node* top(){
    if(size==0){
        return NULL;
    }
    return arr[1];
   }

   void insert(node* x){
    arr[++size]=x;
    int parent=size/2;
    int index =size;
    while(parent>=1){
        if(arr[parent]->data>arr[index]->data){
            swap(arr[parent],arr[index]);
        }
        index = parent;
        parent=parent/2;
    }
   }  

   void print(){
    if(size==0){
        cout<<"Empty";
    }
    int index=1;
    while(index<=size){
        cout<<arr[index++]->data<<" ";
    }cout<<endl;
   }
   void pop(){
    if(size==0){
        cout<<"empty"<<endl;
        return;
    }
    swap(arr[0],arr[size]);
    size--;
    heapify(arr,0,size);
   }
};



int main(){
    int arr[3][4]={{3,5,7,-1},{4,6,8,-1},{1,2,8,-1}};
    int r=3;
    int c=4;
    heap h;

    int ans[r*(c-1)];
    int index=0;

    for(int i=0;i<r;i++){
        node* a=new node(i,0,arr[i][0]);
        h.insert(a);
    } 
    h.print();
    
    while(h.size>0){
        ans[index++]=h.top()->data;
        if(arr[h.top()->i][h.top()->j+1]!=-1){
            node* b= new node(h.top()->i,h.top()->j+1,arr[h.top()->i][h.top()->j+1]);
            h.pop();
            h.insert(b);
        }
        else{
            h.pop();
        } 
    }
    for(int i=0;i<r*(c-1);i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

}

