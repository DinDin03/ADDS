#include <vector>
#include <string>
#include <unordered_map>

// Trie node structure
struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode();
};

class Autocomplete {
    TrieNode* root;

    void dfs(TrieNode* node, std::string prefix, std::vector<std::string>& suggestions);

public:
    Autocomplete();
    ~Autocomplete(); // Destructor to free memory
    void insert(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord);
};
