#include <string>
#include <vector>

class ternaryTrieNode {
    public:
        ternaryTrieNode* newNode(char data);
        void insert(ternaryTrieNode** root, const std::string& word, int index = 0);

        ternaryTrieNode* findPrefixNode(ternaryTrieNode* root, const std::string& prefix, int index = 0);
        void collectWords(ternaryTrieNode* node, std::string currentWord, std::vector<std::string>& results);
        std::vector<std::string> autocomplete(ternaryTrieNode* root, const std::string& prefix);

    private:
        char data;
        bool isEndOfString = false;
        ternaryTrieNode *left, *eq, *right;
};