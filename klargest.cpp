#include <vector>
#include <queue>
#include <stdexcept>

int kth_largest(const std::vector<int>& values, int k) {
    if (k <= 0 || k > values.size()) {
        throw std::invalid_argument("k is out of bounds");
    }

    std::priority_queue<int> maxHeap(values.begin(), values.end());

    for (int i = 0; i < k - 1; ++i) {
        maxHeap.pop();
    }

    return maxHeap.top();
}
