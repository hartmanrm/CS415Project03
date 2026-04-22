#include <string>
#include <vector>

class standardTrieNode {
    public:
        standardTrieNode();
        void insert(standardTrieNode* root, const std::string& key);

        standardTrieNode* findPrefixNode(standardTrieNode* root, const std::string& prefix);
        void collectWords(standardTrieNode* node, std::string currentWord, std::vector<std::string>& results);
        std::vector<std::string> autocomplete(standardTrieNode* root, const std::string& prefix);

    private:
        standardTrieNode* children[26];
        bool isLeaf;
};