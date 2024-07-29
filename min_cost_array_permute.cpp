#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> original;
    int score = INT_MAX;
    vector<int> result;
    void generatePermutations(std::vector<int>& nums, int start, int end) {
        if (start == end) {
            check(nums);
        } else {
            for (int i = start; i <= end; ++i) {
                std::swap(nums[start], nums[i]);            // Swap
                generatePermutations(nums, start + 1, end); // Recurse
                std::swap(nums[start], nums[i]);            // Backtrack
            }
        }
    }

    bool lex(vector<int> &arr){
        for(int i=0; i<arr.size(); i++){
            if(arr[i] < result[i]) return true;
            else if(arr[i] > result[i]) return false;
        }
        return false;
    }
    void check(vector<int>& perm) {
        int cost = 0;
        int n = perm.size();
        for (int i = 0; i < n; i++) {
            cost += abs(perm[i] - original[perm[(i + 1) % n]]);
        }
        if (cost < score) {
            result = perm;
            score = cost;
        }
        if (cost == score) {
            if(lex(perm)){
                result = perm;
            }
        }
    }
    vector<int> findPermutation(vector<int>& nums) {
        original = nums;
        sort(nums.begin(), nums.end());
        generatePermutations(nums, 0, nums.size()-1);
        return result;
    }
};