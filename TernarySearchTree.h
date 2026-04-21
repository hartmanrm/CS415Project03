
class ternaryTrieNode{
    public:
        ternaryTrieNode* newNode(char data);
        void insert(ternaryTrieNode** root, char* word);

    
    private:
        char data;
        unsigned isEndOfString = 1; // True if this character is last character of one of the words
        ternaryTrieNode *left, *eq, *right;
};
