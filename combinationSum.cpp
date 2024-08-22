#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> solve(unordered_map<int, unordered_map<int, vector<vector<int>>>> &dp, vector<int> &candidates, int curr, int leftover){
        if(curr == candidates.size() || leftover <= 0){
            if(leftover == 0){
                return vector<vector<int>>(1);
            }
            return vector<vector<int>>(0);
        }
        if(dp[curr].find(leftover) != dp[curr].end()) return dp[curr][leftover];

        vector<vector<int>> case1 = solve(dp, candidates, curr + 1, leftover - candidates[curr]);
        vector<vector<int>> case2 = solve(dp, candidates, curr + 1, leftover);

        for(auto collection: case1){
            collection.push_back(candidates[curr]);
            case2.push_back(collection);
        }

        return dp[curr][leftover] = case2;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, unordered_map<int, vector<vector<int>>>> dp;
        vector<vector<int>> res = solve(dp, candidates, 0, target);
        vector<vector<int>> ans;
        for(auto collection: res){
            sort(collection.begin(), collection.end());
            bool state = true;
            for(auto check: ans){
                if(collection == check){
                    state = false;
                    break;
                }
            }
            if(state){
                ans.push_back(collection);
            }
        }
        return ans;
    }
};