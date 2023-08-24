#include <iostream>

// Helper function for tail recursion with an accumulator
int sumIntegersTail(int n, int accumulator) {
  // Base case: if n is 0, return the accumulator
  if (n == 0) {
    return accumulator;
  }
  // Tail recursive case: decrement n and add it to the accumulator
  return sumIntegersTail(n - 1, accumulator + n);
}
// Wrapper function to initiate the tail recursion
int sumIntegers(int n) {
  // Call the tail-recursive function with an initial accumulator of 0
  return sumIntegersTail(n, 0);
}
int main() {
  int n;
  std::cout << "Enter a positive integer n: ";
  std::cin >> n;
  if (n < 1) {
    std::cout << "Please enter a positive integer." << std::endl;
  } else {
    int result = sumIntegers(n);
    std::cout << "Sum of integers from 1 to " << n << " is: " << result
              << std::endl;
  }
  return 0;
}
