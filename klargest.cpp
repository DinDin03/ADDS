#include <vector>
#include <queue>
#include <stdexcept>

int kth_largest(std::vector<int> values, int k) {
    if (k <= 0 || k > values.size()) {
        throw std::invalid_argument("k is out of bounds");
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    for (int value : values) {
        minHeap.push(value);

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return minHeap.top();
}
