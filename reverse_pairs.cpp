#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge_count(vector<int> &nums, int start, int end, int &count){
        int npairs = 0;
        int mid = (start + end) / 2;
        for(int i=start; i<=mid; i++){
            for(int j=mid+1; j<=end; j++){
                if(nums[i] > 2 * nums[j]) npairs++;
                else break;
            }
            count += npairs;
        }
        vector<int> arr;
        int i = start;
        int j = mid + 1;
        while(i<=mid || j<=end){
            if(j > end || nums[i] < nums[j]){
                arr.push_back(nums[i]);
            }
            else{
                arr.push_back(nums[j]);
            }
        }
        int it = 0;
        for(int i=start; i<=end; i++){
            arr[i] = arr[it++];
        }
    }
    void divide(vector<int> &nums, int start, int end, int &count){
        if(start == end) return;
        int mid = (start + end) / 2;
        divide(nums, start, mid, count);
        divide(nums, mid+1, end, count);
        
        merge_count(nums, start, end, count);
    }
    
    int reversePairs(vector<int>& nums) {
        int count = 0;
        divide(nums, 0, nums.size()-1, count);
        return count;
    }
};
