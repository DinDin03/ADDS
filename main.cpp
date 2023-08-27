// main.cpp
#include <iostream>
#include "Finder.h"

int main() {
    std::string s1, s2;

    std::cout << "Enter s1: ";
    std::cin >> s1;

    std::cout << "Enter s2: ";
    std::cin >> s2;

    Finder finder;
    std::vector<int> results = finder.findSubstrings(s1, s2);

    if (results.size() == 1 && results[0] == -1) {
        std::cout << "No matches found." << std::endl;
    } else {
        std::cout << "Found matches at positions: ";
        for (int i = 0; i < results.size(); i++) {
            std::cout << results[i];
            if (i < results.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
