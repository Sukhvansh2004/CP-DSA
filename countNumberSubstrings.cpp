#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> zero;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '0'){
                zero.push_back(i);
            }
        }
        int n = s.length();
        int res = 0;
        int ind = 0;
        for(int l=0; l<n; l++){
            while(ind < zero.size() && zero[ind] < l) ind++;

            vector<int> valid0;
            for(int zero_ind=ind; zero_ind<min((int)zero.size(), int(ind+sqrt(n))); zero_ind++){
                valid0.push_back(zero[zero_ind]);
            }
            valid0.push_back(n);
            
            int last = l;
            int cnt = 0;
            for(auto idx: valid0){
                int reqOnes = cnt * cnt;
                int end = max(l + reqOnes + cnt - 1, last);
                
                if(end < idx) {
                    res += idx - end;
                }
                last = end;
                cnt++;
            }
        }
        return res;
    }
};