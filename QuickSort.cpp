#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list) {
    if (list.size() <= 1) {
        return list;
    }

    int pivot = list[list.size() / 2];
    std::vector<int> left, right, equal;

    for (int num : list) {
        if (num < pivot) {
            left.push_back(num);
        } else if (num > pivot) {
            right.push_back(num);
        } else {
            equal.push_back(num);
        }
    }

    left = sort(left);
    right = sort(right);

    left.insert(left.end(), equal.begin(), equal.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
}
