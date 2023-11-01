#include <iostream>
#include <vector>

using namespace std;

class graph{
public:
    vector<vector<int>> G;
    graph(int V = 0){
        G = vector<vector<int>>(V);
    }

    void insert_vertex(){
        vector<int> arr;
        G.push_back(arr);
    }

    void insert_edge(int a, int b){
        if(a<G.size() && b<G.size()) G[a].push_back(b);
        else cout<<"The vertex does not exist"<<endl;
    }

    graph transpose(){
        graph Gt(G.size());
        for(int i=0;i<G.size();i++){
            for(int j=0;j<G[i].size();j++){
                Gt.insert_edge(G[i][j],i);
            }
        }
        return Gt;
    }

    void print(){
        for(int i=0;i<G.size();i++){
            cout<<i<<": ";
            for(int j=0;j<G[i].size();j++){
                cout<<G[i][j]<<' ';
            }
            cout<<endl;
        }
    }

};

void DFS(graph &adj, vector<bool> &is_visited, vector<int> &tp, int &i, int &t){
    if(is_visited[i]) return;
    is_visited[i] = true;
    vector<int> arr = adj.G[i];
    for(int j=0;j<arr.size();j++){
        DFS(adj, is_visited, tp,  arr[j], t);
    }
    tp[i] = t++;
}

vector<int> DFSA(graph &adj, vector<int> &add, vector<bool> &is_visited, int &node){
    if(is_visited[node]) return add;
    is_visited[node] = true;
    add.push_back(node);
    for(int i=0;i<adj.G[node].size();i++){
        DFSA(adj, add, is_visited, adj.G[node][i]);
    }
    return add;
}

vector<vector<int>> strongly_connected(graph &adj){
    vector<bool> is_visited(adj.G.size(), false);
    vector<int> tp(adj.G.size(), 0);
    int t = 1;
    for(int i=0;i<adj.G.size();i++){
        if(!is_visited[i]) DFS(adj, is_visited, tp, i, t);
    }
    graph G_transpose = adj.transpose();

    vector<int> sorted_nodes(tp.size());
    for(int i=0;i<tp.size();i++){
        sorted_nodes[tp[i]-1] = i;
    }

    vector<vector<int>> scc;
    is_visited.clear();
    is_visited.resize(G_transpose.G.size(), false);

    for(int i=sorted_nodes.size()-1;i>=0;i--){
        vector<int> arr;
        arr= DFSA(G_transpose, arr, is_visited, sorted_nodes[i]);
        if(arr.size()!=0){
            scc.push_back(arr);
        }
    }
    return scc;
}

int main(){
    int N, m;
    cin>>N>>m;
    graph G(N+1);
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        G.insert_edge(a, b);
    }
    vector<vector<int>> scc = strongly_connected(G);
    vector<int> arr;
    vector<bool> is_visited(N+1, false);
    for(int i=0;i<scc.size();i++){
        if(scc[i].size()==1){
            DFSA(G, arr, is_visited, scc[i][0]);
        }
    }
    if(arr.size() == N + 1) cout<<1;
    else cout<<-1;
    
    return 0;
}