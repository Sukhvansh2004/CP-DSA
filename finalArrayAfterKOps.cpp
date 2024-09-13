#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long MOD = 1000000007;
    vector<int> getFinalState(vector<long long>& nums, long long k, long long multiplier) {
        vector<long long> res(nums.size(), 0);       //Change array
        auto cmp = [](pair<long long, long long> a, pair<long long, long long> b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        };                                  //Comparator
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, decltype(cmp)> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
        }                                           //Initialise pq
        int ops = k;
        unordered_set<int> reached;
        while(reached.size() < nums.size()){
            pair<long long, long long> a = pq.top();
            pq.pop();
            pair<long long, long long> b = pq.top();
            double div = double(b.first)/a.first;
            int amount = ceil(log(div) / log(multiplier)); 
            if(ops == 0){
                break;
            }
            else if(ops - amount < 0){
                a.first = a.first * ops * multiplier;
                ops -= ops;
                break;
            } else{
                a.first *= amount * multiplier;
                ops -= amount;
            }
            pq.push(a);
            reached.insert(a.second);
        }                               

        while(!pq.empty()){
            pair<long long, long long> b = pq.top();
            pq.pop();
            res[b.second] = b.first;
        }
        
        vector<int> result(nums.size(), 0);
        if(ops > 0){
            int iter = ops / k;
            int remain = ops%k;
            if(iter > 0){
                for(int i=0; i<res.size(); i++){
                    long long val = res[i] / nums[i];
                    res[i] *= val * iter;
                }
            } 
            result = getFinalState(res, remain, multiplier);
        } else{
            for(int i=0; i<res.size(); i++){
                result[i] =  res[i] % MOD;
            }
        }
        return result;
    }
    vector<int> getFinalState(vector<int>& nums, long long k, long long multiplier) {
        if(nums.size() == 1){
            return {((nums[0] % MOD) * (ceil(pow(multiplier, k)) % MOD)) % MOD};
        }
        vector<long long> res(nums.size(), 0);       //Change array
        auto cmp = [](pair<long long, long long> a, pair<long long, long long> b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        };                                  //Comparator
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, decltype(cmp)> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
        }                                           //Initialise pq
        int ops = k;
        unordered_set<int> reached;
        while(reached.size() < nums.size()){
            pair<long long, long long> a = pq.top();
            pq.pop();
            pair<long long, long long> b = pq.top();
            double div = double(b.first)/double(a.first);
            int amount = ceil(log(div) / log(multiplier)); 
            if(ops == 0){
                break;
            }
            else if(ops - amount < 0){
                a.first = a.first * ops * multiplier;
                ops -= ops;
                break;
            } else{
                a.first *= amount * multiplier;
                ops -= amount;
            }
            pq.push(a);
            reached.insert(a.second);
        }                               

        while(!pq.empty()){
            pair<long long, long long> b = pq.top();
            pq.pop();
            res[b.second] = b.first;
        }
        
        vector<int> result(nums.size(), 0);
        if(ops > 0){
            int iter = ops / k;
            int remain = ops%k;
            if(iter > 0){
                for(int i=0; i<res.size(); i++){
                    long long val = res[i] / nums[i];
                    res[i] *= val * iter;
                }
            } 
            result = getFinalState(res, remain, multiplier);
        } else{
            for(int i=0; i<res.size(); i++){
                result[i] =  res[i] % MOD;
            }
        }
        return result;
    }
};