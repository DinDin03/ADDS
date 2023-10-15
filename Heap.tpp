#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <cmath>  // for floor
#include <stdexcept> // for runtime_error
#include <algorithm> // for swap

template <typename T>
class Heap {
 private:
  std::vector<T> values;
  void heapify(int);

 public:
  Heap();  // constructs an empty heap
  Heap(std::vector<T>); // constructs a heap with the values from the given vector

  void insert(T);
  void remove(T);
  T getMin();
};

template <typename T>
Heap<T>::Heap() {}

template <typename T>
Heap<T>::Heap(std::vector<T> start_values) {
  for (int i = 0; i < start_values.size(); i++) {
    values.push_back(start_values.at(i));
  }

  int initial_parent_index = std::floor(values.size() / 2) - 1;
  for (int parent_index = initial_parent_index; parent_index >= 0; parent_index--) {
    heapify(parent_index);
  }
}

template <typename T>
void Heap<T>::insert(T value) {
    values.push_back(value);
    int index = values.size() - 1;

    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (values[parentIndex] > values[index]) {
            std::swap(values[parentIndex], values[index]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

template <typename T>
void Heap<T>::remove(T value) {
    int index = -1;
    for (int i = 0; i < values.size(); i++) {
        if (values[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) return;

    values[index] = values.back();
    values.pop_back();

    heapify(index);
}

template <typename T>
T Heap<T>::getMin() {
    if (values.empty()) throw std::runtime_error("Heap is empty");
    return values[0];
}

template <typename T>
void Heap<T>::heapify(int parent_index) {
    if (parent_index < 0 || parent_index >= values.size()) return;

    int left_child_index = parent_index * 2 + 1;
    int right_child_index = parent_index * 2 + 2;

    int index_of_smallest = parent_index;

    if (left_child_index < values.size() &&
        values.at(left_child_index) < values.at(index_of_smallest)) {
        index_of_smallest = left_child_index;
    }

    if (right_child_index < values.size() &&
        values.at(right_child_index) < values.at(index_of_smallest)) {
        index_of_smallest = right_child_index;
    }

    if (index_of_smallest != parent_index) {
        std::swap(values.at(parent_index), values.at(index_of_smallest));
        heapify(index_of_smallest);
    }
}

#endif // HEAP_H
