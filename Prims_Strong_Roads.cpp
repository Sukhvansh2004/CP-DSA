#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

struct Comp{
    bool operator()(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b){
        return a.second.second<b.second.second;
    }
};

struct road{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        return a.second>b.second;
    }
};

class Graph{
public:;
    vector<vector<pair<int,int>>> G;
    Graph(int V=0){
        G.resize(V);
    };

    void addEdge(int a, int b, int w){
        if(a<G.size() && b<G.size()){
            G[a].push_back(make_pair(b, w));
            G[b].push_back(make_pair(a, w));
        }
    }

    void addVertex(){
        vector<pair<int,int>> a;
        G.push_back(a);
    }

    void print(){
        for(int i=0; i<G.size();i++){
            for(auto j: G[i]){
                cout<<i<<"->"<<j.first<<":"<<j.second<<endl;
            }
        }
    }
};

Graph MST(Graph &E){
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, Comp> pq;
    if(E.G.size()==0) return E;
    for(auto edge: E.G[0]){
        pq.push(make_pair(0,edge));
    }
    vector<bool> is_visited(E.G.size(), false);
    is_visited[0] = true;
    Graph mst(E.G.size());
    while(!pq.empty()){
        pair<int,pair<int,int>> edge;
        edge = pq.top();
        pq.pop();
        int a = edge.first;
        pair<int,int> weight = edge.second;
        if(is_visited[weight.first]) continue;
        is_visited[weight.first] = true;
        mst.addEdge(a, weight.first, weight.second);
        for(auto i: E.G[weight.first]){
            pq.push(make_pair(weight.first,i));
        }
    }
    return mst;
}

int main(){
    int N, M, K;
    cin>>N>>M>>K;
    Graph adj(N);
    for(int i=0;i<M;i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj.addEdge(a-1, b-1, w);
    }
    Graph mst = MST(adj);
    priority_queue<pair<int,int>, vector<pair<int,int>>, road> pq;
    for(auto i: mst.G){
        for(auto j: i){
            pq.push(j);
        }
    }
    int count=0;
    if(!pq.empty()){
        while(!pq.empty()){
            pair<int,int> edge = pq.top();
            pq.pop();
            K-=edge.second;
            if(K>=0) count++;
            else break;
        }
        cout<<count;
    }
    else cout<<-1;
    return 0;
}