#include "StandardTrie.h"
#include <string>

// from geeksforgeeks link provided by dr. gill
standardNode::standardNode(){
    // initialize the wordEnd variable with false
    // initialize every index of childNode array with NULL
    isLeaf = false;
    for (int i = 0; i < 26; i++) {
        children[i] = nullptr;
    }
}

// from geeksforgeeks link provided by dr. gill
void standardNode::insert(standardNode* root, const std::string& key){
    // Initialize the curr pointer with the root node
    standardNode* curr = root;

    // Iterate across the length of the string
    for (char c : key) {
      
        // Check if the node exists for the 
        // current character in the Trie
        if (curr->children[c - 'a'] == nullptr) {
          
            // If node for current character does 
            // not exist then make a new node
            standardNode* newNode = new standardNode();
          
            // Keep the reference for the newly
            // created node
            curr->children[c - 'a'] = newNode;
        }
      
        // Move the curr pointer to the
        // newly created node
        curr = curr->children[c - 'a'];
    }

    // Mark the end of the word
    curr->isLeaf = true;
}
