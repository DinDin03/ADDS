#include "BigNumCalc.h"
#include <list>
#include <string>
#include <algorithm>

std::list<int> bigNumCalc::buildBigNum(const std::string& numString) {
    std::list<int> result;
    for (char c : numString) {
        if (std::isdigit(c)) {
            result.push_back(c - '0');
        }
    }
    return result;
}

std::list<int> bigNumCalc::add(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    int carry = 0;

    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend() || carry) {
        int sum = carry;

        if (it1 != num1.rend()) {
            sum += *it1;
            ++it1;
        }

        if (it2 != num2.rend()) {
            sum += *it2;
            ++it2;
        }

        carry = sum / 10;
        sum %= 10;
        result.push_front(sum);
    }

    return result;
}

std::list<int> bigNumCalc::sub(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result;
    int borrow = 0;

    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();

    while (it1 != num1.rend() || it2 != num2.rend()) {
        int x = (it1 != num1.rend()) ? *it1 : 0;
        int y = (it2 != num2.rend()) ? *it2 : 0;

        int diff = x - y - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.push_front(diff);

        if (it1 != num1.rend()) {
            ++it1;
        }
        if (it2 != num2.rend()) {
            ++it2;
        }
    }

    // Remove leading zeros
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](int x) { return x != 0; }));

    return result;
}

std::list<int> bigNumCalc::mul(const std::list<int>& num1, int num2) {
    std::list<int> result;
    int carry = 0;

    for (auto it = num1.rbegin(); it != num1.rend(); ++it) {
        int product = (*it * num2) + carry;
        carry = product / 10;
        product %= 10;
        result.push_front(product);
    }

    if (carry) {
        result.push_front(carry);
    }

    return result;
}

// Implement multiplication of two big numbers represented as lists
std::list<int> bigNumCalc::mul(const std::list<int>& num1, const std::list<int>& num2) {
    std::list<int> result(num1.size() + num2.size(), 0);

    auto it1 = num1.rbegin();
    int carry = 0;

    for (int i = 0; it1 != num1.rend(); ++it1, ++i) {
        auto it2 = num2.rbegin();
        int k = i;
        carry = 0;

        for (; it2 != num2.rend(); ++it2, ++k) {
            int product = (*it1 * *it2) + result[k] + carry;
            carry = product / 10;
            result[k] = product % 10;
        }

        while (carry) {
            int sum = result[k] + carry;
            carry = sum / 10;
            result[k] = sum % 10;
            ++k;
        }
    }

    // Remove leading zeros
    result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](int x) { return x != 0; }));

    return result;
}
