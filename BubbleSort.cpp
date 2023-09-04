#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list) {
    int n = list.size();
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (list[i] > list[i + 1]) {
                std::swap(list[i], list[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);

    return list;
}
