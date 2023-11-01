#include <iostream>
#include <cmath>
using namespace std;

class Node{
public:
    int parent=-1;
    int state=0;
    int key=INT_MAX;
    int data;
};  

class heap{
public:
    pair<int,int> *arr;
    int heap_size=0;
    int capacity=1;
    heap(){
        this->arr=new pair<int,int>[capacity];
    }

    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i +2;
    }

    int parent(int i){
        return ceil(float(i)/float(2))-1;
    }

    void insert(pair<int,int> n){
        if(heap_size!=capacity){
            arr[heap_size++]=n;
        }
        else{
            pair<int,int>* temp=new pair<int,int>[2*capacity];
            capacity=2*capacity;
            for(int j=0;j<heap_size;j++){
                temp[j]=arr[j];
            }
            temp[heap_size++]=n;
            delete[] arr;
            this->arr=temp;
        }
        
        int k=heap_size-1;
        while(k>0 && arr[k].second<arr[parent(k)].second){
            swap(arr[k],arr[parent(k)]);
            k=parent(k);
        };
    }

    void heapify(int k){
        int minimum=k;
        if(left(k)<heap_size && arr[minimum]>arr[left(k)]){
            minimum=left(k);
        }
        if(right(k)<heap_size && arr[minimum]>arr[right(k)]){
            minimum=right(k);
        }

        if(minimum!=k){
            swap(arr[minimum],arr[k]);
            heapify(minimum);
        }

    }

    void increase(int i,int k){
        arr[i].second=k;
        heapify(i);
    }

    pair<int,int> minh(){
        pair<int,int> t=arr[0];
        arr[0].second=INT_MAX;
        heapify(0);
        heap_size--;
        return t;
    }

};

template <typename T>
class darray{
public:
    T *arr;
    int size=0;
    int capacity=1;
    darray(){
        this->arr=new T[capacity];
    }

    void insert(T n){
        if(size!=capacity){
            arr[size++]=n;
        }
        else{
            T *temp=new T[2*capacity];
            capacity=2*capacity;
            for(int i=0;i<size;i++){
                temp[i]=arr[i];
            }
            temp[size++]=n;
            delete[] arr;
            this->arr=temp;
        }
    }
};

class Graph{
public:
    pair<Node,darray<pair<int,int>>> *G;
    int elements=0;
    int maxe;
    Graph(int n){
        this->maxe=n;
        this->G=new pair<Node,darray<pair<int,int>>>[n];
    }

    int search(int u){
        for(int i=0;i<elements;i++){
            if(G[i].first.data==u) return i;
        }
    }
    void addVertex(int u){
        if(elements<maxe){
            G[elements++].first.data=u;
        }
    }

    void addEdge(int u,int v,int w){
        int t=search(u);
        pair<int,int> ele;
        ele.first=v;
        ele.second=w;
        G[t].second.insert(ele);

        t=search(v);
        ele.first=u;
        ele.second=w;
        G[t].second.insert(ele);
    }
};

void prims(Graph &adj,int u){
    int k=adj.search(u);
    adj.G[k].first.state=1;
    for(int i=0;i<adj.G[k].second.size;i++){
        int t=adj.G[k].second.arr[i].first;
        int index=adj.search(t);
        if(adj.G[index].first.key>adj.G[k].second.arr[i].second && adj.G[index].first.state==0){
            adj.G[index].first.key=adj.G[k].second.arr[i].second;
            adj.G[index].first.parent=adj.G[k].first.data;

        }
    }
    int mini=INT_MAX;
    int temp;
    for(int i=0;i<adj.elements;i++){
        if(adj.G[i].first.state==0 && adj.G[i].first.key<mini){
            mini=adj.G[i].first.key;
            temp=adj.G[i].first.data;
        }
    }
    if(mini!=INT_MAX){
        prims(adj,temp);
    }
}

int main(){
    Graph adj(4);
    adj.addVertex(1);
    adj.addVertex(2);
    adj.addVertex(3);
    adj.addVertex(4);   
    adj.addEdge(1,2,3);
    adj.addEdge(2,4,2);
    adj.addEdge(1,3,5);
    adj.addEdge(3,4,1);
    adj.G[0].first.key=0;
    adj.G[0].first.parent=-1;
    adj.G[0].first.state=1;
    prims(adj,1);
    int weight=0;
    for(int i=0;i<adj.elements;i++){
        cout<<"Data: "<<adj.G[i].first.data<<" , "<<"Key: "<<adj.G[i].first.key<<" , "<<"Parent: "<<adj.G[i].first.parent<<" , "<<"State: "<<adj.G[i].first.state<<endl;
        weight+=adj.G[i].first.key;
    }
    cout<<endl<<"Total Weight: "<<weight<<endl;
}