#include <iostream>
#include <vector>

#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include "Sort.h"

int main() {
  std::vector<int> inputList;
  int num;

  while (std::cin >> num) {
    inputList.push_back(num);
  }

  Sort* sorter = new QuickSort();
  RecursiveBinarySearch searcher;

  std::vector<int> sortedList = sorter->sort(inputList);
  bool found = searcher.search(sortedList, 1);

  std::cout << (found ? "true" : "false");
  for (int num : sortedList) {
    std::cout << " " << num;
  }
  std::cout << std::endl;

  delete sorter;

  return 0;
}
