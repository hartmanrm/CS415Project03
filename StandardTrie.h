#include <string>

class standardNode {
    public:
        standardNode();
        void insert(standardNode* root, const std::string& key);

    private:
        char value;
        standardNode* children[26];
        bool isLeaf;
};

class StandardTrie{
    public:
        void constructTrie(std::string fileName);

    private:

};
