#include <string>
#include <vector>

class ternaryTrieNode {
    public:
        //ternaryTrieNode(){root = nullptr;}
        ternaryTrieNode* newNode(char data);
        void insert(ternaryTrieNode** root, const char* word);

        //ternaryTrieNode* findPrefixNode(ternaryTrieNode* root, const std::string& prefix, int index = 0);
        ternaryTrieNode* findPrefixNode(ternaryTrieNode** root, const char* word);
        void collectWords(ternaryTrieNode* node, std::string currentWord, std::vector<std::string>& results);
        std::vector<std::string> autocomplete(ternaryTrieNode* root, const std::string& prefix);

        void print(ternaryTrieNode* node, std::string currentWord = "");
    private:
        char data;
        bool isEndOfString = false;
        ternaryTrieNode *left, *eq, *right;
};