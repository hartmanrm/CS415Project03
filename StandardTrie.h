#include <string>

class standardTrieNode {
    public:
        standardTrieNode();
        void insert(standardTrieNode* root, const std::string& key);

    private:
        //char value;
        standardTrieNode* children[26];
        bool isLeaf;
};

