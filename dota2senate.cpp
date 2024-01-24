
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<char> majority_push;
        vector<char> majority_pop;
        int skip = 0;
        for(char s: senate){
            if((majority_push.empty() && (majority_pop.empty() || majority_pop[0] == s)) || (!majority_push.empty() && majority_push.back() == s)){
                majority_push.push_back(s);
            }
            else if(skip>0) skip--;
            else{
                majority_push.push_back(s);
                if(majority_pop.empty()){
                    while(!majority_push.empty()) {
                        majority_pop.push_back(majority_push.back());
                        majority_push.pop_back();
                    }
                }
                majority_pop.pop_back();
            }
        }
        return majority.back() == 'R' ? "Radiant" : "Dire";
    }   
};