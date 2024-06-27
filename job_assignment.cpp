#include <bits/stdc++.h>
using namespace std;

struct CompareFirstElement {
    bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        // Return true if p1 should have a lower priority than p2 (max heap)
        return p1.first < p2.first;
    }
};

class Solution {
public:
    int findLargestSmaller(const std::vector<int>& arr, int x) {
        int left = 0;
        int right = arr.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If arr[mid] is less than or equal to x, update result and search in the right half
            if (arr[mid] <= x) {
                result = mid;
                left = mid + 1;
            } else {
                // If arr[mid] is greater than x, search in the left half
                right = mid - 1;
            }
        }

        // Return the index of the largest element smaller than x
        return result;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CompareFirstElement> maxPQ;
        for(int i=0; i<profit.size(); i++){
            maxPQ.push(make_pair(profit[i], difficulty[i]));
        }
        sort(worker.begin(), worker.end());
        int n = worker.size();
        vector<bool> employed(n, false);

        int result = 0;
        while(!maxPQ.empty() && n>0){
            pair<int, int> assignment = maxPQ.top();
            maxPQ.pop();
            int index = findLargestSmaller(worker, assignment.second);
            cout<<index<<" ";
            while(index != -1 && !employed[index]){
                index--;
            }
            if(index != -1){
                result += assignment.first;
                employed[index] = true;
                n--;
            }
        }
        return result;
    }
};