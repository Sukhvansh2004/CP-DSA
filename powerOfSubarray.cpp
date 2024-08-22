#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        vector<int> result;
        int restart = 0;
        int len = 1;
        for(int i=1; i<k; i++){
            if(nums[i] == nums[i-1] + 1){
                len++;
            } else{
                restart += len;
                len = 1;
            }
        }
        if(restart == 0){
            result.push_back(nums[k-1]);
        } else{
            result.push_back(-1);
            restart--;
        }
        for(int i=k; i<nums.size(); i++){
            if(nums[i] == nums[i-1] + 1 && restart == 0){
                result.push_back(nums[i]);
            } 
            else if(nums[i] == nums[i-1] + 1){
                restart--;
                len++;
                result.push_back(-1);
            }
            else{
                restart--;
                restart += len; //min(len, k-1);
                len = 1;
                result.push_back(-1);
            }
        }
        return result;
    }
};