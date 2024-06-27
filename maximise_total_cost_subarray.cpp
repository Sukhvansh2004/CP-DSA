#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long reduction(vector<int>& nums, vector<vector<long long>>& dp, int start, int prev) {
        if (start >= nums.size()) {
            return 0;
        }

        if (dp[start][prev] != -1) {
            return dp[start][prev];
        }

        if (prev == 0 || prev == 2) {
            long long option1 = reduction(nums, dp, start + 1, 0);
            long long option2 = nums[start] + reduction(nums, dp, start + 1, 1);
            dp[start][prev] = max(option1, option2);
        } else if (prev == 1) {
            long long option1 = reduction(nums, dp, start + 1, 0);
            long long option2 = -nums[start] + reduction(nums, dp, start + 1, 2);
            dp[start][prev] = max(option1, option2);
        }

        return dp[start][prev];
    }

    long long maximumTotalCost(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(3, -1));
        return reduction(nums, dp, 0, 0);
    }
};