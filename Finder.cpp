#include "Finder.h"
#include <iostream>
#include <chrono>

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2) {
    std::vector<int> result;
    for (size_t i = 0; i <= s1.size() - s2.size(); i++) {
        bool match = true;
        for (size_t j = 0; j < s2.size(); j++) {
            if (s1[i + j] != s2[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            result.push_back(i);
        }
    }
    if (result.empty()) {
        result.push_back(-1);
    }
    return result;
}
