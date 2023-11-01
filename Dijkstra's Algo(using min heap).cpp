#include <bits/stdc++.h>

using namespace std;


int minDistance(vector<int>& dist, vector<bool>& visited) {
  int min_index = -1;
  int min_dist = INT_MAX;
  for (int i = 0; i < dist.size(); i++) {
    if (!visited[i] && dist[i] < min_dist) {
      min_dist = dist[i];
      min_index = i;
    }
  }
  return min_index;
}


vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
  vector<int> dist(adj.size(), INT_MAX);
  vector<bool> visited(adj.size(), false);

  dist[src] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, src});

  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();

    if (visited[u]) {
      continue;
    }

    visited[u] = true;

    for (auto& neighbor : adj[u]) {
      int v = neighbor.first;
      int weight = neighbor.second;

      if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }
  return dist;
}

int main() {
  vector<vector<pair<int, int>>> adj = {{}, {{1, 10}, {2, 3}}, {{1, 4}}, {}};
  vector<int> dist =dijkstra(adj, 0);

  for (int i = 0; i < adj.size(); i++) {
    cout << "Shortest distance from source to vertex " << i << ": " << dist[i] << endl;
  }

  return 0;
}
