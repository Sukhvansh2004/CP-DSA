#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> merge_k_sorted_lists(vector<vector<int>>& lists) {
    // Create an empty result vector and a min-heap.
    vector<int> result;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> heap;

    // Add the first element of each list to the heap.
    for (int i = 0; i < lists.size(); i++) {
        if (!lists[i].empty()) {
            heap.push({ lists[i][0], { i, 0 } });
        }
    }

    while (!heap.empty()) {
        auto p = heap.top();
        heap.pop();
        int val = p.first;
        int list_index = p.second.first;
        int element_index = p.second.second;
        result.push_back(val);
        if (element_index < lists[list_index].size() - 1) {
            int next_element = lists[list_index][element_index + 1];
            heap.push({ next_element, { list_index, element_index + 1 } });
        }
    }

    return result;
}

int main() {
    vector<vector<int>> lists = { { 1, 4, 5 }, { 1, 3, 4 }, { 2, 6 } };
    vector<int> result = merge_k_sorted_lists(lists);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
