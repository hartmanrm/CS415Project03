#include "StandardTrie.h"
#include <string>
#include <iostream>

// from geeksforgeeks link provided by dr. gill
standardTrieNode::standardTrieNode(){
    // initialize the wordEnd variable with false
    // initialize every index of childNode array with NULL
    isLeaf = false;
    for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
}

// from geeksforgeeks link provided by dr. gill
void standardTrieNode::insert(standardTrieNode* root, const std::string& key){
    // Initialize the curr pointer with the root node
    standardTrieNode* curr = root;

    // Iterate through each char in the string
    for (int i = 0; i < key.length(); i++){
        char c = key[i];

        // Check if the node exists for the 
        // current character in the Trie
        if (curr->children[c - 'a'] == nullptr) { 
            //(c - 'a' gives the index of c in the children array)

            // If node for current character does not exist then make a new node
            standardTrieNode* newNode = new standardTrieNode();
          
            // store the reference for the newly created node
            curr->children[c - 'a'] = newNode;
        }
      
        // Move the curr pointer to the newly created node
        curr = curr->children[c - 'a'];
    }

    // when done mark the end of the word
    curr->isLeaf = true;
}

standardTrieNode* standardTrieNode::findPrefixNode(standardTrieNode* root, const std::string& prefix) {
    standardTrieNode* curr = root;

    for (int i = 0; i < prefix.length(); i++) {
        char c = prefix[i];

        if (curr->children[c - 'a'] == nullptr) {
            return nullptr;
        }

        curr = curr->children[c - 'a'];
    }

    return curr;
}

void standardTrieNode::collectWords(standardTrieNode* node, std::string currentWord, std::vector<std::string>& results) {
    if (node == nullptr) {
        return;
    }

    if (node->isLeaf) {
        results.push_back(currentWord);
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            char nextChar = 'a' + i;
            collectWords(node->children[i], currentWord + nextChar, results);
        }
    }
}

std::vector<std::string> standardTrieNode::autocomplete(standardTrieNode* root, const std::string& prefix) {
    std::vector<std::string> results;

    standardTrieNode* prefixNode = findPrefixNode(root, prefix);
    if (prefixNode == nullptr) {
        return results;
    }

    collectWords(prefixNode, prefix, results);
    return results;
}

// DELETE LATER
void standardTrieNode::print(standardTrieNode* node, std::string currentWord) {
    if (node == nullptr) {
        return;
    }

    if (node->isLeaf) {
        std::cout << currentWord << std::endl;
    }

    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            char nextChar = 'a' + i;
            print(node->children[i], currentWord + nextChar);
        }
    }
}