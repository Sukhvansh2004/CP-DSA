#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort edges by weight
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

// Initialize parent and rank vectors
void makeSet(vector<int> &parent, vector<int> &rank, int n){
    for(int i = 0; i < n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find the parent of a node and update the parent vector
int findParent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }
    // Update parent and return parent node
    return parent[node] = findParent(parent, parent[node]);
}

// Merge two sets based on their ranks
void UnionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findParent(parent, u);
    v = findParent(parent, v);

    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else{
        parent[u] = v;
        rank[v]++;
    }
}

// Find the minimum spanning tree
int minimumSpanningTree(vector<vector<int>> &edges, int n){
    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);
    
    // Initialize parent and rank vectors
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;

    // Iterate over edges and merge sets
    for(int i = 0; i < edges.size(); i++){
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v){
            // Add weight to minimum spanning tree
            minWeight += wt;
            UnionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

int main(){
    vector<vector<int>> graph{{1, 2, 2}, {1, 3, 6}, {2, 4, 3}, {2, 5, 5}, {5, 4, 7}};
    cout << minimumSpanningTree(graph, 6);
}
