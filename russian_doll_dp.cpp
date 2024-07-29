#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(vector<int> &dp, vector<vector<int>> &envelopes, int index){
        if(dp[index] != -1) return dp[index];

        int tmp = 1;
        for(int i = 0; i<envelopes.size(); i++){
            if(envelopes[i][0] < envelopes[index][0] && envelopes[i][1] <  envelopes[index][1]) {
                tmp = max(tmp, 1 + solve(dp, envelopes, i));
            }
        }
        return dp[index] = tmp;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> dp(envelopes.size(), -1);
        int maxi = 0;
        for(int i=0; i<dp.size(); i++){
            maxi = max(maxi, solve(dp, envelopes, i));
        }
        return maxi;
    }
};