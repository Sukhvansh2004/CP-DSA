#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

public:
    SegmentTree(vector<int>& array) {
        n = array.size();
        tree.resize(2 * n);
        build(array);
    }

    void build(vector<int>& array) {
        // Initialize leaf nodes in the segment tree
        for (int i = 0; i < n; ++i) {
            tree[n + i] = array[i];
        }

        // Build the segment tree by calculating parent nodes
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

    void update(int index, int value) {
        // Update the value at index in the original array and then update the segment tree
        if(index < 0 || index >= n) return;
        int pos = n + index;
        if(tree[pos] != value){
            tree[pos] = value;

            while (pos > 1) {
                pos /= 2;
                tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
            }
        }
    }

    int range_sum(int l, int r) {
        // Calculate sum in range [l, r]
        l += n;
        r += n;
        int sum = 0;

        while (l <= r) {
            if (l % 2 == 1) {
                sum += tree[l];
                l++;
            }
            if (r % 2 == 0) {
                sum += tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }

        return sum;
    }

    void print(){
        for(int i=n; i<2*n; i++){
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }
};


class Solution {
public:

    bool isPeak(vector<int> &nums, int index){
        return (index > 0 && index < nums.size() - 1 && nums[index] > nums[index-1] && nums[index] > nums[index+1]) ? true : false;
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> peaks(nums.size(), 0);
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                peaks[i] = 1;
                i++;
            }
        }
        SegmentTree tree(peaks);
        vector<int> result;
        for(auto query: queries){
            if(query[0] == 1){
                result.push_back(tree.range_sum(query[1]+1, query[2]-1));
            }
            else{
                nums[query[1]] = query[2];
                int n = query[1];
                if(isPeak(nums, n)){
                    tree.update(n, 1);
                    tree.update(n-1, 0);
                    tree.update(n+1, 0);
                }
                else{
                    if(isPeak(nums, n-1)) tree.update(n-1, 1);
                    else tree.update(n-1, 0);
                    if(isPeak(nums, n+1)) tree.update(n+1, 1);
                    else tree.update(n+1, 0);

                    tree.update(n, 0);
                }
            }
        }
        return result;
    }
};