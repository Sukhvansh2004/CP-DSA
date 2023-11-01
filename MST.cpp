#include <iostream>
using namespace std;

class connect{
    public:
    int data;
    int weigth;
};

class Node{
    public:
    int data;
    int d=INT_MAX;
    int f=0;
    int pi=0;
};

class weight{
    public:
    int weight;
    int data;

};

template <typename T>
class darray{
    public:
    T *a;
    int capacity=1;
    int size=0;
    darray(){
        this->a=new T[capacity];
    }

    void insert(T n){
        if(size==capacity){
            T* temp=new T[capacity*2];
            for(int i=0;i<size;i++){
                temp[i]=a[i];
            }
            capacity=capacity*2
            temp[size++]=n;
            delete[] a;
            this->a=temp;
        }
        else{
            a[size++]=n;
        }
    }

    void del(int index){
        if(index>=size) return;
        T *temp=new T[--size];
        size=0;
        for(int i=0;i<size;i++){
            if(i==index){}
            else{
                temp[size++]=a[i]
            }
        }
        delete[] a;
        this->a=temp;        
    }

};

class graph{
    public:
    pair<Node,darray<weight>>* G;
    int maxe;
    int elements;
    graph(int n){
        this->maxe=n;
        this->elements=0;
        this->G=new pair<Node,darray<weight>>[maxe];
    }

    void addVertex(Node u){
        if (elements<maxe){
            G[elements++].first=u;
        }
    }

    void addEdge(int u, int v, int w){
        for(int i=0;i<elements;i++){
            if(G[i].first.data==u ){
                weight W;
                W.data=v;
                W.weight=w;
                G[i].second.insert(W);
            }
            else if(G[i].first.data==v ){
                weight W;
                W.data=u;
                W.weight=w;
                G[i].second.insert(W);
            }
        }
    }

};



