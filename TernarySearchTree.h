#include <string>
#include <vector>

class ternaryTrieNode {
    public:
        //ternaryTrieNode();
        ternaryTrieNode* newNode(char data);
        void insert(ternaryTrieNode** root, const char* word);

        //ternaryTrieNode* findPrefixNode(ternaryTrieNode* root, const std::string& prefix, int index = 0);
        ternaryTrieNode* findPrefixNode(ternaryTrieNode** root, const char* word);
        void collectWords(ternaryTrieNode* node, std::string currentWord, std::vector<std::string>& results);
        std::vector<std::string> autocomplete(ternaryTrieNode* root, const std::string& prefix);

        void print(ternaryTrieNode* node, std::string currentWord = "");
        int getBuildTime(){return buildTime;}
        int getTotalSpace(){return totalSpace;}
    private:
        int buildTime = 0, totalSpace = 0;
        char data;
        bool isEndOfString = false;
        ternaryTrieNode *left, *eq, *right;
};