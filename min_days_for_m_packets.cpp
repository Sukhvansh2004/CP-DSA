#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         if(m * k > bloomDay.size()) return -1;

        vector<bool> marked(bloomDay.size(), false);
        for(int i=0; i<m; i++){
            int j = 0;
            int mini = INT_MAX;
            int index = -1;
            while(j < bloomDay.size() - k){
                if(!marked[j]){
                    int wait = bloomDay[j];
                    int remaining = k;
                    int curr = j;
                    while(remaining>0 && curr<bloomDay.size()){
                        if(!marked[curr]){
                            wait = max(wait, bloomDay[curr]);
                            remaining--;
                        }
                        curr++;
                    }
                    if(remaining==0 && wait<mini){
                        mini = wait;
                        index = j;
                    }
                }
                cout<<j<<" "<<mini<<" "<<marked[j]<<" "<<endl;
                j++;
            }
            cout<<"BREAK"<<endl<<endl;
            if(index != -1){
                for(int m=0; m<k; m++){
                    marked[index+m] = true;
                }
            }
        }
        int maxi = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(marked[i]){
                maxi = max(maxi, bloomDay[i]);
            }
        }
        for(bool i: marked) cout<<i<<" "; 
        return maxi;
    }
};