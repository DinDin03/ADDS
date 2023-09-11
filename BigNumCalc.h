#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H

#include <list>
#include <string>

class BigNumCalc {
public:
    // Default constructor and destructor
    BigNumCalc();
    ~BigNumCalc();

    // Method to create a list representing a big number from a string
    std::list<int> buildBigNum(const std::string& numString);

    // Method to add two big numbers
    std::list<int> add(const std::list<int>& num1, const std::list<int>& num2);

    // Method to subtract two big numbers
    std::list<int> sub(const std::list<int>& num1, const std::list<int>& num2);

    // Method to multiply a big number by a single-digit number
    std::list<int> mul(const std::list<int>& num1, const std::list<int>& num2);
};

#endif // BIGNUMCALC_H
