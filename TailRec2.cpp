#include <iostream>
double powerTail(double x, int n, double result) {
    // Base case: If n is 0, return the accumulated result
    if (n == 0) {
        return result;
    }

    // If n is even, update x and halve n
    if (n % 2 == 0) {
        x = x * x;
        n = n / 2;
    } else {
        // If n is odd, update result and decrement n by 1
        result = result * x;
        n = n - 1;
    }
    return powerTail(x, n, result);
}
double power(double x, int n) {
    return powerTail(x, n, 1.0); // Start with an initial result of 1.0
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
