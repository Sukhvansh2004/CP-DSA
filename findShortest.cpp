#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int t, c;
    int calcTime(int length){
        int time = 0;
        int ctime = 0;
        while(length > 0){
            if(ctime >= c){
                int swaps = ctime / c;
                if(swaps%2 != 0){
                    time += c - ctime % c;
                }
                ctime = 0;
            }
            time += t;
            ctime += t;
            length--;
        }
        return time;
    }
    void findPath(vector<vector<int>> &graph, vector<bool> &visited, int length, int start, int end, int &shortest, int &secondShortest){
        if(start == end){
            if(length < shortest){
                secondShortest = shortest;
                shortest = length;
                if(secondShortest == INT_MAX){
                    secondShortest = length+2;
                }
                return;
            }
            if(length > shortest && length < secondShortest){
                secondShortest = length;
            }
        }
        if(visited[start]) return;

        visited[start] = true;
        for(int adj: graph[start]){
            findPath(graph, visited, length + 1, adj, end, shortest, secondShortest);
        }
        visited[start] = false;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<bool> visited(n+1, false);
        vector<vector<int>> graph(n+1);
        t = time;
        c = change;
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int shortest = INT_MAX;
        int secondShortest = INT_MAX;

        findPath(graph, visited, 0, 1, n, shortest, secondShortest);
        return calcTime(secondShortest);
    }
};