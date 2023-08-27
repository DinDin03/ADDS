#include "Finder.h"
#include <iostream>

std::vector<int> Finder::findSubstrings(const std::string& s1, const std::string& s2) {
    std::vector<int> result;
    int n = s1.size();
    int m = s2.size();
    
    for (int i = 0; i <= n - m; i++) {
        bool match = true;
        for (int j = 0; j < m; j++) {
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
