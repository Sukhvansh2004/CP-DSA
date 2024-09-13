#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        int zeroK = k;
        int oneK = k;
        int start = 0;
        int res = 0;
        vector<int> substr(s.length(), 0);
        for(int end=0; end<s.length(); end++){
            if(s[end] == '0' && (zeroK > 0 || oneK >= 0)){
                substr[end] += end - start + 1;
                zeroK--;
            } 
            else if(s[end] == '1' && (zeroK >= 0 || oneK > 0)){
                substr[end] += end - start + 1;
                oneK--;
            }
            else if(s[end] == '0'){
                while(zeroK<=0 && oneK<0){
                    if(s[start++] == '1'){
                        oneK++;
                    } else {
                        zeroK++;
                    }
                }
                zeroK--;
                substr[end] += end - start + 1;
            }
            else {
                while(zeroK<0 && oneK<=0){
                    if(s[start++] == '1'){
                        oneK++;
                    } else {
                        zeroK++;
                    }
                }
                oneK--;
                substr[end] += end - start + 1;
            }
        }
        vector<long long> substrMerge(s.length(), 0);

        substrMerge[0] = substr[0];
        for(int i=1; i<substrMerge.size(); i++){
            substrMerge[i] += substrMerge[i-1] + substr[i];
        }

        vector<long long> result;
        for(auto query: queries){
            int end = query[1];
            int start = query[0];
            long long res = substrMerge[end];
            if(start > 0){
                res -= substrMerge[start-1];
                int thresh = 1;
                while(substr[start] > thresh){
                    res -= substr[start] - thresh++;
                }
            }
            result.push_back(res);
        }
        return result;
    }
};