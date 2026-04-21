#include "StandardTrie.h"
#include <string>

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
