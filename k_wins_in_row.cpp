#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        deque<int> players;
        for(int i=0; i<skills.size(); i++){
            players.push_back(i);
        }
        unordered_map<int, int> counter;
        while(true){
            int p1 = players[0];
            int p2 = players[1];
            if(skills[p1] < skills[p2]){
                counter[p2]++;
                counter[p1] = 0;
                if(counter[p2] == k) return p2;
                players.push_back(p1);
                players.pop_front();
            }
            else{
                counter[p1]++;
                counter[p2] = 0;
                if(counter[p1] == k) return p1;
                players.push_back(p2);
                players.pop_front(); 
                players.pop_front();
                players.push_front(p1);
            }
        }
        return -1;
    }
};