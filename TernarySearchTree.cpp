#include "TernarySearchTree.h"

ternaryTrieNode* ternaryTrieNode::newNode(char data){
    ternaryTrieNode* temp = new ternaryTrieNode();
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = nullptr;
    return temp;

}
/*
void ternaryTrieNode::insert(ternaryTrieNode** root, char* word){
    // Base Case: Tree is empty
    if (!(*root))
        *root = newNode(*word);

    // If current char is SMALLER than root's character, then 
    // insert this word in LEFT subtree of root
    if ((*word) < (*root)->data)
        insert(&((*root)->left), word);

    // If curr char GREATER than root's character, then 
    // insert this word in RIGHT subtree ofroot
    else if ((*word) > (*root)->data)
        insert(&((*root)->right), word);

    // If current character of word is same as root's character,
    else {
        if (*(word + 1))
            insert(&((*root)->eq), word + 1);

        // the last character of the word
        else
            (*root)->isEndOfString = 1;
    }
}
*/
void ternaryTrieNode::insert(ternaryTrieNode** root, const std::string& word, int index) {
    if (word.empty()) return;

    char c = word[index];

    if (*root == nullptr) {
        *root = newNode(c);
    }

    if (c < (*root)->data) {
        insert(&((*root)->left), word, index);
    }
    else if (c > (*root)->data) {
        insert(&((*root)->right), word, index);
    }
    else {
        if (index + 1 < word.length()) {
            insert(&((*root)->eq), word, index + 1);
        }
        else {
            (*root)->isEndOfString = true;
        }
    }
}

ternaryTrieNode* ternaryTrieNode::findPrefixNode(ternaryTrieNode* root, const std::string& prefix, int index) {
    if (root == nullptr || prefix.empty()) return nullptr;

    char c = prefix[index];

    if (c < root->data) {
        return findPrefixNode(root->left, prefix, index);
    }
    else if (c > root->data) {
        return findPrefixNode(root->right, prefix, index);
    }
    else {
        if (index == prefix.length() - 1) {
            return root;
        }
        return findPrefixNode(root->eq, prefix, index + 1);
    }
}

ternaryTrieNode* ternaryTrieNode::findPrefixNode(ternaryTrieNode* root, const std::string& prefix, int index) {
    if (root == nullptr || prefix.empty()) return nullptr;

    char c = prefix[index];

    if (c < root->data) {
        return findPrefixNode(root->left, prefix, index);
    }
    else if (c > root->data) {
        return findPrefixNode(root->right, prefix, index);
    }
    else {
        if (index == prefix.length() - 1) {
            return root;
        }
        return findPrefixNode(root->eq, prefix, index + 1);
    }
}

std::vector<std::string> ternaryTrieNode::autocomplete(ternaryTrieNode* root, const std::string& prefix) {
    std::vector<std::string> results;

    if (prefix.empty()) return results;

    ternaryTrieNode* prefixNode = findPrefixNode(root, prefix, 0);
    if (prefixNode == nullptr) return results;

    if (prefixNode->isEndOfString) {
        results.push_back(prefix);
    }

    collectWords(prefixNode->eq, prefix, results);

    return results;
}