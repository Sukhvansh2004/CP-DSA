#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &profits, vector<vector<bool>> &skillsForJobs, vector<vector<bool>> &skillsOfCandidates, string &employed, int curr, unordered_map<string, unordered_map<int, int>> &dp) {
    if (curr >= skillsOfCandidates.size()) return 0;

    if (dp[employed].find(curr) != dp[employed].end()) return dp[employed][curr];

    int prof = 0;
    for (int i = 0; i < profits.size(); i++) {
        bool state = true;
        if(employed[i] == '0'){
            for (int j = 0; j < skillsForJobs[i].size(); j++) {
                state = state && (!skillsForJobs[i][j] || skillsOfCandidates[curr][j]);
            }
            if (state) {
                employed[i] = '1';
                prof = max(prof, profits[i] + solve(profits, skillsForJobs, skillsOfCandidates, employed, curr + 1, dp));
                employed[i] = '0';
            }
        }
        prof = max(prof, solve(profits, skillsForJobs, skillsOfCandidates, employed, curr + 1, dp));
    }
    return dp[employed][curr] = prof;
}

int solution(vector<int> profits, vector<vector<bool>> skillsForJobs, vector<vector<bool>> skillsOfCandidates) {
    string employed(profits.size(), '0');
    unordered_map<string, unordered_map<int, int>> dp;
    return solve(profits, skillsForJobs, skillsOfCandidates, employed, 0, dp);
}
