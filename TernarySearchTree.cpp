#include "TernarySearchTree.h"
#include <iostream>
/*
ternaryTrieNode::ternaryTrieNode(){
    buildTime = 0;
} */

ternaryTrieNode* ternaryTrieNode::newNode(char data){
    ternaryTrieNode* temp = new ternaryTrieNode();
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = nullptr;
    totalSpace += 3;
    return temp;
}

void ternaryTrieNode::insert(ternaryTrieNode** root, const char* word){
    if (word == nullptr || *word == '\0'){
        return;
    }
    // Base Case: Tree is empty
    if (!(*root)){
        *root = newNode(*word);
    }

    // If current char is SMALLER than root's character, then 
    // insert this word in LEFT subtree of root
    buildTime++;
    if ((*word) < (*root)->data){
        insert(&((*root)->left), word);
    }
    // If curr char GREATER than root's character, then 
    // insert this word in RIGHT subtree of root
    else if ((*word) > (*root)->data){
        insert(&((*root)->right), word);
    }
    // If current character of word is same as root's character,
    else {
        if (*(word + 1)){
            insert(&((*root)->eq), word + 1);
        }
        else { // the last character of the word
            (*root)->isEndOfString = 1;
        }
    }
}

/*
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
}*/
/*
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
}*/

ternaryTrieNode* ternaryTrieNode::findPrefixNode(ternaryTrieNode** root, const char* word){
    if (root == nullptr || word == nullptr) return nullptr;

    if (*word < (*root)->data){
        return findPrefixNode(&((*root)->left), word);
    }
    else if (*word > (*root)->data){
        return findPrefixNode(&((*root)->right), word);
    }
    else{
        if (*(word + 1)){
            return findPrefixNode(&((*root)->eq), word + 1);
        }
        else{
            return *root;
        }
    }
}

std::vector<std::string> ternaryTrieNode::autocomplete(ternaryTrieNode* root, const std::string& prefix) {
    std::vector<std::string> results;

    if (prefix.empty()) return results;

    const char* prefixAsArr = prefix.c_str();
    ternaryTrieNode* prefixNode = findPrefixNode(&root, prefixAsArr);
    if (prefixNode == nullptr) return results;

    if (prefixNode->isEndOfString) {
        results.push_back(prefix);
    }

    collectWords(prefixNode->eq, prefix, results);

    return results;
}

void ternaryTrieNode::collectWords(ternaryTrieNode* node, std::string currentWord, std::vector<std::string>& results) {
    if (node == nullptr) {
        return;
    }

    collectWords(node->left, currentWord, results);

    std::string newWord = currentWord + node->data;
    if (node->isEndOfString) {
        results.push_back(newWord);
    }

    collectWords(node->eq, newWord, results);

    collectWords(node->right, currentWord, results);
}

// DELETE LATER
void ternaryTrieNode::print(ternaryTrieNode* node, std::string currentWord) {
    if (node == nullptr) {
        return;
    }

    // Visit left subtree
    print(node->left, currentWord);

    // Build current word
    std::string newWord = currentWord + node->data;

    // Print if this node ends a word
    if (node->isEndOfString) {
        std::cout << newWord << std::endl;
    }

    // Visit equal subtree
    print(node->eq, newWord);

    // Visit right subtree
    print(node->right, currentWord);
}