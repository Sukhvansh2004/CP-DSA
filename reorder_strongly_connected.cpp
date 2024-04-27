#include <bits/stdc++.h>
using namespace std;

bool sortBySecond(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.second < b.second;
}

class Solution {
public:
    void DFS(vector<vector<int>>& graph, int node, vector<bool>& is_visited, vector<pair<int, int>>& index, int& d) {
        if (!is_visited[node]) {
            is_visited[node] = true;
            index[node].second = d++;
            for (int cities : graph[node]) {
                DFS(graph, cities, is_visited, index, d);
            }
        }
    }

    void DFS(vector<vector<int>>& graph, int node, vector<bool>& is_visited) {
        if (!is_visited[node]) {
            is_visited[node] = true;
            for (int cities : graph[node]) {
                DFS(graph, cities, is_visited);
            }
        }
    }

    vector<vector<int>> transpose(vector<vector<int>> graph) {
        vector<vector<int>> graph_T(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                graph_T[j].push_back(i);
            }
        }
        return graph_T;
    }

    int strongly_connected(vector<vector<int>>& graph) {
        vector<pair<int, int>> index(graph.size());
        for (int i = 0; i < index.size(); i++) {
            index[i].first = i;
            index[i].second = 0;
        }

        vector<bool> is_visited(graph.size(), false);
        int t = 0;

        for (int i = 0; i < graph.size(); i++) {
            DFS(graph, i, is_visited, index, t);
        }

        std::sort(index.begin(), index.end(), sortBySecond);
        is_visited.clear();
        is_visited.resize(graph.size(), false);

        vector<vector<int>> graph_T = transpose(graph);
        int result = 0;

        for (auto node : index) {
            if (!is_visited[node.first]) {
                DFS(graph_T, node.first, is_visited);
                result++;
            }
        }

        return result;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (int i = 1; i < n; i++) {
            graph[0].push_back(i);
        }

        for (auto edge : connections) {
            if (edge[1] > 0) {
                graph[edge[1]].push_back(edge[0]);
            }
        }

        return strongly_connected(graph);
    }
};
