#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int d=INT_MAX;
    int pi=NULL;
    int color=0;
};

class queue{
    public:
    Node* arr;
    int size;
    int capacity;
    queue(){
        this->arr=new Node[1];
        this->size=0;
        this->capacity=1;
    }
    void enqueue(Node t){
        if(size==capacity){
            Node* temp=new Node[capacity*2];
            for(int i=0;i<size;i++){
                temp[i]=arr[i];
            }
            temp[size++]=t;
            capacity=2*capacity;
            delete[] arr;
            this->arr=temp;
        }
        else{
            arr[size++]=t;
        }
    }
    Node dequeue(){
        return arr[--size];
    }
     
    bool empty(){
        if(size==0){
            return true;
        }
        return false;
    }

};

class stack{
    public:
    int size;
    int capacity;
    int *arr;
    stack(){
        this->size=0;
        this->capacity=1;
        this->arr=new int[capacity];
    }
    void push(int n){
        if(size==capacity){
            int *temp=new int[2*capacity];
            for(int i=0;i<size;i++){
                temp[i]=arr[i];
            }
            delete[] arr;
            this->arr=temp;
            arr[size++]=n;
            capacity=2*capacity;
        }
        else{
            arr[size++]=n;
        }
    }  
    void pop(){
        if(size==0){
            cout<<"Stack is empty"<<endl;
        }
        else{
            size--;
        }
    }
};

class graph{
    public:
    pair<Node,stack> *G;
    int maxe;
    int elements;
    graph(int n){
        this->G=new pair<Node,stack>[n];
        this->elements=0;
        this->maxe=n;
    }
    void addEdge(int u,int v, int direction){
        if (direction==1){
            for(int i=0;i<elements;i++){
                if(G[i].first.data==u){
                    G[i].second.push(v);
                }
                else if(G[i].first.data==v){
                    G[i].second.push(u);
                }
            }
        }
        else if(direction==0){
            for(int i=0;i<elements;i++){
                if(G[i].first.data==u){
                    G[i].second.push(v);
                }
            }
        }
    }
    void addvertex(Node u){
        if(elements<maxe){
            this->G[elements++].first=u;
        }
    }
    void print(){
        for(int i=0;i<elements;i++){
            cout<<G[i].first.data<<"-->";
            for(int j=0;j < G[i].second.size ; j++){
                cout<<G[i].second.arr[j]<<" ";
            }
            cout<<endl;
        }
    }

    pair<int,int>* outdegree(){
        pair<int,int>* outd=new pair<int , int>[elements];
        for(int i=0;i<elements;i++){
            outd[i].first=G[i].first.data;
            outd[i].second=G[i].second.size;
        }
        return outd;
    }
    pair<int,int>* indegree(){
        pair<int,int>* ind=new pair<int , int>[elements];
        for(int i=0;i<elements;i++){
            ind[i].first=G[i].first.data;
            ind[i].second=0;
            for(int j=0;j<elements;j++){
                for(int k=0;k<G[j].second.size;k++){
                    if(G[j].second.arr[k]==G[i].first.data){
                        ind[i].second++;
                    }
                }
            }
        }
        return ind;
    }
};

int search(graph adj, int s){
    for(int i=0;i<adj.elements;i++){
        if(adj.G[i].first.data==s){
            return i;
        }
    }
} 
graph BFS(graph adj, int s){
    int index=search(adj,s);
    queue arr;
    for(int i=0;i<adj.elements;i++){
        adj.G[i].first.color=0;
        adj.G[i].first.d=INT_MAX;
        adj.G[i].first.pi=NULL;
    }
    adj.G[index].first.color=1;
    adj.G[index].first.d=0;
    adj.G[index].first.pi=NULL;
    arr.enqueue(adj.G[index].first);
    while(!arr.empty()){
        Node t=arr.dequeue();
        int val=search(adj,t.data);
        for(int i=0;i<adj.G[val].second.size;i++){
            int ins=search(adj,adj.G[val].second.arr[i]);
            if(adj.G[ins].first.color==0){
                adj.G[ins].first.color=1;
                adj.G[ins].first.d=t.d+1;
                adj.G[ins].first.pi=t.data;
                arr.enqueue(adj.G[ins].first);
            }
        }
        adj.G[val].first.color=2;
    }
    return adj;
}



int main(){
    cout<<"Enter the no. of elements in the graph: "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the vertices: "<<endl;
    graph adj(n);
    for(int i=0;i<n;i++){
        Node t;
        cin>>t.data;
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

    pair<int, int>* outd=adj.outdegree();
    pair<int, int>* ind=adj.indegree();
    cout<<"The outdegree of the graph is :"<<endl;
    for(int i=0;i<adj.elements;i++){
        cout<<outd[i].first<<" : "<<outd[i].second<<endl;
    }
    cout<<"The indegree of the graph is :"<<endl;
    for(int i=0;i<adj.elements;i++){
        cout<<ind[i].first<<" : "<<ind[i].second<<endl;
    }
    
    int z;
    cout<<"Enter the value to start the BFS: ";
    cin>>z;
    adj=BFS(adj,z);
    cout<<"The BFS traversal of the graph is: "<<endl;
    for(int i=0;i<adj.elements;i++){
        cout<<adj.G[i].first.data<<": ";
        cout<<"d->"<<adj.G[i].first.d<<" ";
        cout<<"color->"<<adj.G[i].first.color<<" ";
        cout<<"pi->"<<adj.G[i].first.pi<<" ";
        cout<<endl;
    }
}