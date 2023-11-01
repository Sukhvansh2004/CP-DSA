#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    int d = INT32_MAX;
    int f=0;
    int pi=NULL;
    int color=0;
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
void DFSV(graph &adj,int i,int &time){
    adj.G[i].first.d=++time;
    adj.G[i].first.color=1;
    for(int j=0;j<adj.G[i].second.size;j++){
        int index=search(adj, adj.G[i].second.arr[j]);
        if(adj.G[index].first.color==0){
            adj.G[index].first.pi=adj.G[i].first.data;
            DFSV(adj,index,time);
        }
    }
    adj.G[i].first.color=2;
    adj.G[i].first.f=++time;
}
stack strong_DFSV(graph&adj, int i, int&time, stack strong){
    adj.G[i].first.d=++time;
    adj.G[i].first.color=1;
    for(int j=0;j<adj.G[i].second.size;j++){
        int index=search(adj, adj.G[i].second.arr[j]);
        if(adj.G[index].first.color==0){
            adj.G[index].first.pi=adj.G[i].first.data;
            strong=strong_DFSV(adj,index,time,strong);
        }
    }
    adj.G[i].first.color=2;
    adj.G[i].first.f=++time;
    strong.push(adj.G[i].first.data);
    return strong;
}
stack* strong_DFS(graph adj){
    stack* s=new stack[adj.elements];
    int p=0;
    for(int i=0;i<adj.elements;i++){
        adj.G[i].first.color=0;
        adj.G[i].first.pi=0;
    }
    int time=0;
    for(int i=0;i<adj.elements;i++){
        if(adj.G[i].first.color==0){
            stack strong;
            strong=strong_DFSV(adj,i,time,strong);
            s[p++]=strong;
        }
    }
    return s;
}
void DFS(graph &adj){
    for(int i=0;i<adj.elements;i++){
        adj.G[i].first.color=0;
        adj.G[i].first.pi=0;
    }
    int time=0;
    for(int i=0;i<adj.elements;i++){
        if(adj.G[i].first.color==0){
            DFSV(adj,i,time);
        }
    }
}
void strong(graph adj){
    int time=0;
    for(int i=0;i<adj.elements;i++){
        adj.G[i].first.color=0;
    }
    DFS(adj);
    graph strong_order(adj.maxe);
    for(int i=1;i<adj.elements;i++){
        int j=i;
        while(adj.G[j].first.f>adj.G[j-1].first.f && j>0){
            pair<Node,stack> temp=adj.G[j];
            adj.G[j]=adj.G[j-1];
            adj.G[j-1]=temp;
            j--;
        }
    }
    for(int i=0;i<adj.elements;i++){
        strong_order.addvertex(adj.G[i].first);
    }
    for(int i=0;i<adj.elements;i++){
        for(int j=0;j<adj.G[i].second.size;j++){
            int v= adj.G[i].second.arr[j];
            strong_order.addEdge(v,adj.G[i].first.data,0);
        }
    }
    stack* strong_components=strong_DFS(strong_order);
    cout<<"The strongly connected components are as follows: "<<endl; 
    for(int j=0;j<strong_components->size;j++){   
        stack scc=strong_components[j];
        for(int i=0;i<scc.size;i++){
            cout<<scc.arr[i]<<" ";
        }
        cout<<endl;
    }
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
    
    strong(adj);
}