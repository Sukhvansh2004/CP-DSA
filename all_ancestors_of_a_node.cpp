#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recurse(vector<set<int>> &answers, unordered_map<int, vector<int>> &graph, int node, set<int> ancestor){

        // Perform the union and store the result back into answers[node]
        std::set<int> tempSet;
        std::set_union(answers[node].begin(), answers[node].end(),
                    ancestor.begin(), ancestor.end(),
                    std::inserter(tempSet, tempSet.begin()));

        // Replace answers[node] with the union result
        answers[node] = std::move(tempSet);
        ancestor.insert(node);
        for(int i: graph[node]){
            recurse(answers, graph, i, ancestor);
        }
        // ancestor.pop_back();
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        vector<int> in_degree(n, 0);
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            in_degree[edge[1]]++;
        }
        vector<set<int>> answer(n);
        for(int i=0; i<n; i++){
            if(in_degree[i] == 0){
                set<int> ancestor;
                recurse(answer, graph, i, ancestor);
            }
        }
        vector<vector<int>> answers(n);
        for(int i=0; i<n; i++){
            answers[i] = vector<int>(answer[i].begin(), answer[i].end());
        }
        return answers;
    }
};