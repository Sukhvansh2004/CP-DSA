#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = capital.size();

        // Create a vector of pairs (element, original index)
        vector<pair<int, int>> sorted_capital(n);
        for (int i = 0; i < n; ++i) {
            sorted_capital[i] = make_pair(capital[i], i);
        }

        // Sort the paired array based on the first array's elements
        sort(sorted_capital.begin(), sorted_capital.end());

        // Create new arrays to hold the sorted results
        vector<int> arranged_profit(n);

        // Populate the sorted arrays
        for (int i = 0; i < n; ++i) {
            arranged_profit[i] = profits[sorted_capital[i].second];
        }

        priority_queue<int> pq;
        int j = 0;
        while(true){
            bool state = true;
            while(j < n && state){
                if(sorted_capital[j].first <= w){
                    pq.push(arranged_profit[j++]);
                }
                else state = false;
            }
            if(pq.empty() || k==0){
                return w;
            }
            else{
                w += pq.top();
                pq.pop();
                k--;
            }
        }
        return w;
    }
};