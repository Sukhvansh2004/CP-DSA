#include <iostream>
using namespace std;

class stack{
public:
    int size;
    int capacity;
    int *arr;
    stack(){
        this->size = 0;
        this->capacity = 1;
        this->arr = new int[capacity];
    }
    void push(int n){
        if(size == capacity){
            int *temp = new int[2*capacity];
            for(int i=0; i<size; i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            this->arr = temp;
            capacity *= 2;
        }
        arr[size++] = n;
    }  
    void pop(){
        if(size == 0){
            cout<<"Stack is empty"<<endl;
        }
        else{
            size--;
        }
    }
};

class graph{
public:
    pair<int,stack> *G;
    int maxe;
    int elements;
    graph(int n){
        this->G = new pair<int,stack>[n];
        this->elements = 0;
        this->maxe = n;
    }
    void addEdge(int u,int v, int direction){
        if (direction == 1){
            for(int i=0; i<elements; i++){
                if(G[i].first == u){
                    G[i].second.push(v);
                }
                else if(G[i].first == v){
                    G[i].second.push(u);
                }
            }
        }
        else if(direction == 0){
            for(int i=0; i<elements; i++){
                if(G[i].first == u){
                    G[i].second.push(v);
                }
            }
        }
    }
    void addvertex(int u){
        if(elements < maxe){
            G[elements++].first = u;
        }
    }
    void print(){
        for(int i=0; i<elements; i++){
            cout<<G[i].first<<"-->";
            for(int j=0; j < G[i].second.size ; j++){
                cout<<G[i].second.arr[j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    cout<<"Enter the no. of elements in the graph: "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the vertices: "<<endl;
    graph adj(2);
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        adj.addvertex(t);
    }
    cout<<"Enter the no. of edges: "<<endl;
    int m;
    cin>>m;
    cout<<"Enter the edges along with direction "<<endl;
    for(int i=0;i<m;i++){
        int u,v,direction;
        cin>>u>>v>>direction;
        adj.addEdge(u,v,direction);
    }
    cout<<"The graph is: "<<endl;
    adj.print();
    return 0;
}