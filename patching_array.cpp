class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        unordered_map<int, int> generated;
        for (int i : nums) {
            if (i <= n) {
                generated[i]++;
            }
        }
        int patches = 0;
        int j = 1;
        while (j <= n) {
            if (generated.find(j) == generated.end() || !generated[j]) {
                int k = j - 1;
                long sum = 0;
                while (k > 0) {
                    if (generated.find(k) != generated.end() && generated[k]) {
                        sum += k * generated[k--];
                    }
                    else break;
                }
                if (sum >= j) {
                    for (; j <= min(static_cast<long>(n) ,sum); j++) {
                        if (generated.find(j) != generated.end()) {
                            sum += j * generated[j];
                        }
                    }
                    generated[j] = 1;
                    generated[j-1] = 0;
                } else {
                    patches++;
                    generated[j] = 1;
                }
            }
            j++;
        }
        return patches;
    }
};