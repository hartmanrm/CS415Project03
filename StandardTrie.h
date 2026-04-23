#include <string>
#include <vector>

class standardTrieNode {
    public:
        standardTrieNode();
        void insert(standardTrieNode* root, const std::string& key);

        standardTrieNode* findPrefixNode(standardTrieNode* root, const std::string& prefix);
        void collectWords(standardTrieNode* node, std::string currentWord, std::vector<std::string>& results);
        std::vector<std::string> autocomplete(standardTrieNode* root, const std::string& prefix);

        void print(standardTrieNode* node, std::string currentWord = "");
        //int buildTime = 0;
        int getBuildTime(){return buildTime;}
        int getTotalSpace(){return totalSpace;}
    private:
        int buildTime = 0, totalSpace = 0;
        standardTrieNode* children[26];
        bool isLeaf;
};