#include <iostream>
using namespace std;

class graph{
    public:
    int n;
    int **adj;
    graph(int n){
        this->n=n;
        this->adj=new int*[n]{};
        for(int i=0;i<n;i++){
            this->adj[i]=new int[n]{};
        }
    }
    void addEdge(int u, int v, int direction){
        adj[v][u]=1;
        if(direction==1){
            adj[u][v]=1;
        }
    }
    
    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<adj[j][i]<<" ";
            }
            cout<<endl;
        }
    }

    int *indegree(){
        int *deg=new int[n]{};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1){
                    deg[i]++;
                }
            }
        }
        return deg;
    }

    int *outdegree(){
        int *deg=new int[n]{};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[j][i]==1){
                    deg[i]++;   
                }
            }
        }
        return deg;
    }
};

int main(){
    graph G(5);
    G.addEdge(0,1,1);
    G.addEdge(1,0,1);
    G.addEdge(2,0,1);
    G.addEdge(3,0,1);
    G.addEdge(4,0,1);
    G.addEdge(4,1,1);
    G.addEdge(4,3,0);
    G.addEdge(4,3,0);
    G.print();
    int * ind = G.indegree();
    cout<<"The indegree of the vertices in as follows :"<<endl;
    for(int i=0;i<G.n;i++){
        cout<<i<<" : "<<ind[i]<<endl;
    }
    int * outd = G.outdegree();
    cout<<"The outdegree of the vertices in as follows :"<<endl;
    for(int i=0;i<G.n;i++){
        cout<<i<<" : "<<outd[i]<<endl;
    }
}