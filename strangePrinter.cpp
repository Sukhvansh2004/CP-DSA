#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int strangePrinter(string s) {
        unordered_map<char, int> counts;
        for(int i=0; i<s.length(); i++){
            counts[s[i]] = i;
        }
        string ops(s.length(), ' ');
        int res = 0;
        unordered_map<char, bool> printed;
        for(int i=0; i<s.length(); i++){
            if(s[i] != ops[i] && !printed[s[i]]){
                for(int j=i; j<=counts[s[i]]; j++){
                    ops[j] = s[i];
                }
                printed[s[i]] = true;
                res++;
                cout<<ops<<endl;
            }
        }
        for(int i=0; i<s.length(); i++){
            if(s[i] != ops[i]){
                ops[i] = s[i];
                res++;
                cout<<ops<<endl;
            }
        }
        return res;
    }
};