#include <iostream>

// Function to calculate the greatest common divisor (GCD) using Euclid's
// algorithm
int gcd(int a, int b) {
  if (b == 0) {
    return a;  // GCD(a, 0) = a
  } else {
    return gcd(b, a % b);  // GCD(a, b) = GCD(b, a % b)
  }
}

int main() {
  int num1, num2;

  std::cout << "Enter two positive integers: ";
  std::cin >> num1 >> num2;

  if (num1 <= 0 || num2 <= 0) {
    std::cout << "Please enter positive integers." << std::endl;
  } else {
    int result = gcd(num1, num2);
    std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << result
              << std::endl;
  }

  return 0;
}
