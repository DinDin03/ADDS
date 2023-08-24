#include <iostream>

// Recursive function to calculate x^n
double power(double x, int n) {
    // Base case: x^0 is always 1
    if (n == 0) {
        return 1.0;
    }
    // Recursive case: calculate x^(n/2) and use it to calculate x^n
    double halfPower = power(x, n / 2);
    if (n % 2 == 0) {
        // If n is even, x^n = (x^(n/2))^2
        return halfPower * halfPower;
    } else {
        // If n is odd, x^n = x * (x^(n/2))^2
        return x * halfPower * halfPower;
    }
}
int main() {
    double x;
    int n;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter n (an integer): ";
    std::cin >> n;
    double result = power(x, n);
    std::cout << x << "^" << n << " = " << result << std::endl;
    return 0;
}
