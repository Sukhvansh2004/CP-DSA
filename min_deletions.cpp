#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int, int> freq;
        for(char c: word){
            freq[c]++;
        }
        vector<int> vals;
        for(auto it: freq){
            vals.push_back(it.second);
        }
        sort(vals.begin(), vals.end());

        vector<int> psum(vals.size(), 0);
        psum[0] = vals[0];
        for(int i=1; i<vals.size(); i++){
            psum[i] = psum[i-1] + vals[i];
        }
        int start = 0;
        int numOps = 0;
        while(vals.back() - vals[start] > k){
            int idxDec = upper_bound(vals.begin(), vals.end(), vals[start] + k) - vals.begin();
            int decrease = psum.back() - ((vals.size() - idxDec) * (vals[start] + k)) - psum[idxDec-1];

            int idxInc = lower_bound(vals.begin(), vals.end(), vals.back() - k) - vals.begin();
            int increase = psum[idxInc-1] - (start > 0 ? psum[start-1] : 0);

            int netOps = min(increase, decrease);
            int singleOps = vals[start];
            if(singleOps < netOps){
                numOps += singleOps;
                start++;
            }
            else{
                return numOps + netOps;
            }
        }
        return numOps;
    }
};