#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void recurse(vector<int>& energy, int index, int& k, int& sum) {
        if (index < energy.size()) {
            if (sum < 0)
                sum = 0;

            sum += energy[index];
            recurse(energy, index + k, k, sum);
        }
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int maxi = INT_MIN;
        for (int i = 0; i < min(int(energy.size()), k); i++) {
            int sum = energy[i];
            recurse(energy, i + k, k, sum);
            if (sum > maxi) {
                maxi = sum;
            }
        }
        return maxi;
    }
};