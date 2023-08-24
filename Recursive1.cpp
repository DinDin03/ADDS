#include <iostream>

// Recursive function to calculate the sum of integers from 1 to n
int sumIntegers(int n) {
    // Base case: if n is 1, return 1 (the sum of 1)
    if (n == 1) {
        return 1;
    }

    // Recursive case: add n to the sum of integers from 1 to (n-1)
    return n + sumIntegers(n - 1);
}

int main() {
    int n;
    std::cout << "Enter a positive integer n: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Please enter a positive integer." << std::endl;
    } else {
        int result = sumIntegers(n);
        std::cout << "Sum of integers from 1 to " << n << " is: " << result << std::endl;
    }

    return 0;
}
