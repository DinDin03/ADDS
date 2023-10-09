#include <string>
#include <unordered_map>

// Trie node structure for PrefixMatcher
struct TrieNodeWithRouter {
    std::unordered_map<char, TrieNodeWithRouter*> children;
    int routerNumber;
    TrieNodeWithRouter();
};

class PrefixMatcher {
    TrieNodeWithRouter* root;

public:
    PrefixMatcher();
    ~PrefixMatcher(); // Destructor to free memory
    void insert(std::string address, int routerNumber);
    int selectRouter(std::string networkAddress);
};
