#include <iostream>
#include <vector>

#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include "Sort.h"

int main() {
  // Read input list from stdin
  std::vector<int> inputList;
  int num;

  while (std::cin >> num) {
    inputList.push_back(num);
  }

  // Create instances of sorting and searching classes
  Sort* sorter = new QuickSort();
  RecursiveBinarySearch searcher;

  // Sort the input list
  std::vector<int> sortedList = sorter->sort(inputList);

  // Search for 1 in the sorted list
  bool found = searcher.search(sortedList, 1);

  // Print the result
  std::cout << (found ? "true" : "false");
  for (int num : sortedList) {
    std::cout << " " << num;
  }
  std::cout << std::endl;

  // Clean up
  delete sorter;

  return 0;
}
