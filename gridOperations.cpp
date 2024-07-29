#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<vector<int>>>& dp, vector<vector<int>>& grid, int prev_prev, int prev, int curr) {
        if (curr > grid[0].size()) return 0;

        if (dp[prev_prev][prev][curr] != -1) return dp[prev_prev][prev][curr];

        int ans = 0;
        vector<int> sum(grid.size() + 1, 0);

        // Calculate prefix sums for the current column
        if(curr > 0){
            for (int i = 0; i < grid.size(); i++) {
                sum[i + 1] = grid[i][curr-1] + sum[i];
            }
        }

        // Iterate over all possible choices for the current column
        for (int i = 0; i <= grid.size(); i++) {
            int start = prev;
            int end = (curr < grid.size()) ? max(prev_prev, i) : 0;

            int add = max(0, sum[end] - sum[start]);
            
            ans = max(ans, add + solve(dp, grid, prev, i, curr + 1));
        }

        return dp[prev_prev][prev][curr] = ans;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, -1)));
        return solve(dp, grid, 0, 0, 0);
    }
};
