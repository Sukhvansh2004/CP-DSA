#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<vector<int>>> graph;
priority_queue<vector<vector<int>>, vector<vector<vector<int>>>, [](vector<vector<int>> arr1, vector<vector<int>> arr2) -> bool {return arr1[1][0] > arr2[1][0]}> pq;

vector<int> dijkstra_find(int source, int destination){
    vector<int> plan;
    unordered_map<int, bool> is_visited;
    unordered_map<int, int> distance;
    pq.push({{source}, {0}, {}});           // pushing source node
    int curr = source;
    int dist = 0
    is_visited[source] = true;
    while(!pq.empty() && curr != destination){
        curr = pq.top()[0][0];      //current node
        dist = pq.top()[1][0];     // current distance
        plan = pq.top()[2];          // shortest path to current node
        plan.push_back(curr);
        pq.pop();
        for(auto arr: graph[curr]){
            if(!is_visited[arr[0]] && (distance.find(arr[0]) ==  distance.end() || distance[arr[0]] > dist + arr[1])){
                pq.push({{arr[0]}, {dist + arr[1]}, plan}); // pushing updated node to pq
                distance[arr[0]] = dist + arr[1]; //updating current distance
            }
        }
    }
    if(curr == destination)
        plan.push_back(dist);
        return plan;
    return vector<int>();
}