
#include "Finder.h"

std::vector<int> Finder::findSubstrings(std::string s1, std::string s2) {
    std::vector<int> result;
    int n = s1.size();
    int m = s2.size();
    int i = 0;

    while (i <= n - m) {
        bool match = true;
        int j = 0;
        for (int j = 0; j < m; j++) {
            if (s1[i + j] != s2[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            result.push_back(i);
            i += m;  // Jump to the next possible starting position
        } else {
            if (j == 0) {
                i++;  // No match, increment by 1
            } else {
                i += j;  // Partial match, increment by the length of the prefix found
            }
        }
    }

    if (result.empty()) {
        result.push_back(-1);
    }

    return result;
}
