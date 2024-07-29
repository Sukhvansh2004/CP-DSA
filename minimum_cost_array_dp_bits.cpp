#include <bits/stdc++.h>
using namespace std;

struct Key {
    bitset<14> available; // assuming nums size <= 14
    int myInt;

    bool operator==(const Key& other) const {
        return (available == other.available) && (myInt == other.myInt);
    }
};

// Custom hash function for Key
struct KeyHash {
    size_t operator()(const Key& k) const {
        return hash<bitset<14>>()(k.available) ^ (hash<int>()(k.myInt) << 1);
    }
};

class Solution {
public:
    int n;
    unordered_map<Key, pair<vector<int>, int>, KeyHash> dp;

    pair<vector<int>, int> solve(const bitset<14>& available, int previous, const vector<int>& nums) {
        int index = n - available.count();

        Key key = {available, previous};

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        vector<int> ret;
        vector<int> add;

        int first_element = -1;
        int score = INT_MAX;

        if (index == 0) {
            bitset<14> new_available = available;
            new_available[0] = 0;
            first_element = 0;
            auto up = solve(new_available, 0, nums);
            add = up.first;
            score = up.second;
        } else {
            for (int i = 0; i < n; ++i) {
                if (available[i]) {
                    int curr = abs(previous - nums[i]);
                    bitset<14> new_available = available;
                    new_available[i] = 0;

                    if (index < n - 1) {
                        auto up = solve(new_available, i, nums);
                        curr += up.second;

                        if (curr < score || (curr == score && i < first_element)) {
                            add = up.first;
                            score = curr;
                            first_element = i;
                        }
                    } else {
                        curr += abs(i - nums[0]);
                        first_element = i;
                        score = curr;
                    }
                }
            }
        }

        ret.push_back(first_element);
        ret.insert(ret.end(), add.begin(), add.end());
        return dp[key] = make_pair(ret, score);
    }

    vector<int> findPermutation(vector<int>& nums) {
        n = nums.size();
        bitset<14> available;
        for (int i = 0; i < n; i++) {
            available.set(i);
        }
        return solve(available, -1, nums).first;
    }
};