#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        unordered_map<int, int> differences;
        int count = 0;
        int X;
        int start = 0;
        int end = nums.size() - 1;
        while(start<end){
            int diff = abs(nums[start++] - nums[end--]);
            differences[diff]++;
            if(differences[diff] >= count) {
                if(!(differences[diff] == count && diff > X)){
                    X = diff;
                }
                count = differences[diff];
            }
        }

        int swaps = 0;
        start = 0;
        end = nums.size() - 1;
        while(start<end){
            int diff = abs(nums[start] - nums[end]);
            if(diff != X){
                swaps += 1;
                if((k - min(nums[start], nums[end]) < X) && (max(nums[start], nums[end]) < X))  
                    swaps++;
            }
            start++;
            end--;
        }
        return swaps;
    }
};