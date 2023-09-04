
#include "Finder.h"
using namespace std;
vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    size_t found = s1.find(s2); // Find s2 in s1 once
    while (found != string::npos) {
        result.push_back(found);
        // Update found for the next iteration
        found = s1.find(s2, found + 1);
    }

    if (result.empty()) {
        result.push_back(-1);
    }

    return result;
}



