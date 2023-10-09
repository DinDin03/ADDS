#include "Autocomplete.h"

TrieNode::TrieNode() : isEndOfWord(false) {}

Autocomplete::Autocomplete() {
    root = new TrieNode();
}

Autocomplete::~Autocomplete() {
    // TODO: Implement destructor to free allocated memory
}

void Autocomplete::dfs(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions) {
    if (node->isEndOfWord) {
        suggestions.push_back(prefix);
    }
    for (auto& pair : node->children) {
        dfs(pair.second, prefix + pair.first, suggestions);
    }
}

void Autocomplete::insert(std::string word) {
    TrieNode* current = root;
    for (char c : word) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
    }
    current->isEndOfWord = true;
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    std::vector<std::string> suggestions;
    TrieNode* current = root;
    for (char c : partialWord) {
        if (current->children.find(c) == current->children.end()) {
            return suggestions; // return empty vector if prefix not found
        }
        current = current->children[c];
    }
    dfs(current, partialWord, suggestions);
    return suggestions;
}
