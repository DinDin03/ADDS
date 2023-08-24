#include <iostream>

// Tail-recursive helper function for GCD calculation
int gcdTail(int a, int b, int accumulator) {
    if (b == 0) {
        return accumulator; // GCD(a, 0) = a
    } else {
        return gcdTail(b, a % b, b); // GCD(a, b) = GCD(b, a % b)
    }
}

// Wrapper function to initiate the tail recursion
int gcd(int a, int b) {
    return gcdTail(a, b, a); // Start with an initial accumulator of 'a'
}

int main() {
    int num1, num2;

    std::cout << "Enter two positive integers: ";
    std::cin >> num1 >> num2;

    if (num1 <= 0 || num2 <= 0) {
        std::cout << "Please enter positive integers." << std::endl;
    } else {
        int result = gcd(num1, num2);
        std::cout << "The GCD of " << num1 << " and " << num2 << " is: " << result << std::endl;
    }

    return 0;
}
