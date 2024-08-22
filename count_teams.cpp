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

    int solveTab(vector<int>& rating){
        vector<vector<vector<vector<int>>>> dp(rating.size()+1, vector<vector<vector<int>>>(rating.size()+1, vector<vector<int>>(4, vector<int>(2, -1))));
        for(int prev=rating.size()-1; prev>=-1; prev--){
            for(int curr=rating.size(); curr>=0; curr--){
                for(int remain=0; remain<=3; remain++){
                    for(int inc=0; inc<=1; inc++){
                        if(remain == 0){
                            dp[prev+1][curr][remain][inc] = 1;
                            continue;
                        }
                        else if(curr == rating.size()){
                            dp[prev+1][curr][remain][inc] = 0;
                            continue;
                        }

                        int skip = dp[prev+1][curr+1][remain][inc];
                        int select = 0;

                        if(prev == -1 || (rating[prev] < rating[curr] && inc) || (rating[prev] > rating[curr] && !inc)){
                            select = dp[curr+1][curr+1][remain-1][inc];
                        }
                        dp[prev+1][curr][remain][inc] = skip + select;
                    }
                }
            }
        }
        return dp[0][0][3][0] + dp[0][0][3][1];
    }
    int solveSO(vector<int>& rating){
        vector<vector<vector<int>>> next(rating.size()+1, vector<vector<int>>(4, vector<int>(2, 0)));
        vector<vector<vector<int>>> current(rating.size()+1, vector<vector<int>>(4, vector<int>(2, 0)));
        for(int curr=rating.size(); curr>=0; curr--){
            for(int prev=rating.size()-1; prev>=-1; prev--){
                for(int remain=0; remain<=3; remain++){
                    for(int inc=0; inc<=1; inc++){
                        if(remain == 0){
                            current[prev+1][remain][inc] = 1;
                            continue;
                        }
                        else if(curr == rating.size()){
                            continue;
                        }

                        int skip = next[prev+1][remain][inc];
                        int select = 0;

                        if(prev == -1 || (rating[prev] < rating[curr] && inc) || (rating[prev] > rating[curr] && !inc)){
                            select = next[curr+1][remain-1][inc];
                        }
                        current[prev+1][remain][inc] = skip + select;
                    }
                }
            }
            next = current;
        }
        return current[0][3][0] + current[0][3][1];
    }
    int numTeams(vector<int>& rating) {
        // vector<vector<vector<vector<int>>>> dp(rating.size()+1, vector<vector<vector<int>>>(rating.size()+1, vector<vector<int>>(3, vector<int>(2, -1))));

        // return solve(dp, rating, -1, 0, 2, 1) + solve(dp, rating, -1, 0, 2, 0);
        return solveSO(rating);
    }
};