#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long solve(vector<vector<long long>> &dp, vector<vector<int>>&points, int currRow, int prevCol){
        if(currRow == dp.size()) return 0;

        if(dp[currRow][prevCol+1] != -1) return dp[currRow][prevCol+1];
        
        long long ans = 0;
        if(prevCol == -1){
            for(int i=0; i<points[0].size(); i++) {
                ans = max(ans, solve(dp, points, currRow + 1, i) + points[currRow][i]);
            }
        }
        else{
            for(int i=max(prevCol - points[currRow-1][prevCol], 0); i<min(prevCol + points[currRow-1][prevCol] + 1, (int)points[currRow].size()); i++){
                ans = max(ans, solve(dp, points, currRow + 1, i) + points[currRow][i] - abs(prevCol - i));
            }
        }
        return dp[currRow][prevCol+1] = ans;
    }
    long long maxPoints(vector<vector<int>>& points) {
        vector<vector<long long>> dp(points.size(), vector<long long>(points[0].size() + 1, -1));
        return solve(dp, points, 0, -1);
    }
};