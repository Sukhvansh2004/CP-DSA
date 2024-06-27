#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, int> reduce(vector<int>& arr) {
        if (arr.empty()) return {};
        int j = 0;
        int prev = arr[0];
        int count = 1;
        unordered_map<int, int> result;
        
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != prev) {
                result[prev] = count;
                arr[++j] = arr[i];
                prev = arr[i];
                count = 1;
            } else {
                count++;
            }
        }
        result[prev] = count;
        arr.resize(j + 1);
        return result;
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        unordered_map<int, int> mapping1 = reduce(nums1);
        unordered_map<int, int> mapping2 = reduce(nums2);

        long long count = 0;
        
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (size_t(nums2[j]) * size_t(k) <= size_t(nums1[i])) {
                    if (nums1[i] % (size_t(nums2[j]) * size_t(k)) == 0) {
                        count += static_cast<long long>(mapping1[nums1[i]]) * mapping2[nums2[j]];
                    }
                } else {
                    break;
                }
            }
        }
        
        return count;
    }
};
