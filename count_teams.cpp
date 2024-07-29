#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<vector<vector<vector<int>>>> &dp, vector<int> &rating, int prev, int curr, int remain, bool inc){
        if(curr >= rating.size() || remain == -1) {
            if(remain == -1) return 1;
            return 0;
        };
        if(dp[prev+1][curr][remain][inc] != -1) return dp[prev+1][curr][remain][inc];
        
        int skip = solve(dp, rating, prev, curr+1, remain, inc);
        int select = 0;

        if(prev == -1 || (rating[prev] < rating[curr] && inc) || (rating[prev] > rating[curr] && !inc)){
            select = solve(dp, rating, curr, curr+1, remain-1, inc);
        }

        return dp[prev+1][curr][remain][inc] = skip + select;
    }

    int numTeams(vector<int>& rating) {
        vector<vector<vector<vector<int>>>> dp(rating.size(), vector<vector<vector<int>>>(rating.size()+1, vector<vector<int>>(3, vector<int>(2, -1))));

        return solve(dp, rating, -1, 0, 2, 1) + solve(dp, rating, -1, 0, 2, 0);
    }
};