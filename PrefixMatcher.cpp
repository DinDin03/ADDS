#include "PrefixMatcher.h"

TrieNodeWithRouter::TrieNodeWithRouter() : routerNumber(-1) {}

PrefixMatcher::PrefixMatcher() {
    root = new TrieNodeWithRouter();
}

PrefixMatcher::~PrefixMatcher() {
    // TODO: Implement destructor to free allocated memory
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    TrieNodeWithRouter* current = root;
    for (char c : address) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNodeWithRouter();
        }
        current = current->children[c];
    }
    current->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(std::string networkAddress) {
    TrieNodeWithRouter* current = root;
    int routerNumber = -1;
    for (char c : networkAddress) {
        if (current->children.find(c) == current->children.end()) {
            break;
        }
        current = current->children[c];
        if (current->routerNumber != -1) {
            routerNumber = current->routerNumber;
        }
    }
    return routerNumber;
}
