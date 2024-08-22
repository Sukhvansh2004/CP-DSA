#include <iostream>
#include <vector>
#include <algorithm>

class SegmentTree {
public:
    SegmentTree(const std::vector<int>& data) {
        n = data.size();
        tree.resize(2 * n);
        build(data);
    }

    void update(int index, int value) {
        index += n;  // shift the index to the leaf
        tree[index] = value;
        while (index > 1) {
            index /= 2;
            tree[index] = std::max(tree[2 * index], tree[2 * index + 1]);
        }
    }

    int query(int left, int right) {
        left += n;  // shift the index to the leaf
        right += n;
        int max_value = INT_MIN;
        while (left <= right) {
            if (left % 2 == 1) {
                max_value = std::max(max_value, tree[left]);
                left++;
            }
            if (right % 2 == 0) {
                max_value = std::max(max_value, tree[right]);
                right--;
            }
            left /= 2;
            right /= 2;
        }
        return max_value;
    }

private:
    std::vector<int> tree;
    int n;

    void build(const std::vector<int>& data) {
        // initialize leaves
        for (int i = 0; i < n; ++i) {
            tree[n + i] = data[i];
        }
        // build the tree by calculating parents
        for (int i = n - 1; i > 0; --i) {
            tree[i] = std::max(tree[2 * i], tree[2 * i + 1]);
        }
    }
};

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(data);

    std::cout << "Maximum value in range [1, 4]: " << segTree.query(1, 4) << std::endl;

    segTree.update(3, 10);
    std::cout << "After updating, maximum value in range [1, 4]: " << segTree.query(1, 4) << std::endl;

    return 0;
}
