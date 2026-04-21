#include "TernarySearchTree.h"

ternaryTrieNode* ternaryTrieNode::newNode(char data){
    ternaryTrieNode* temp = new ternaryTrieNode();
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = nullptr;
    return temp;

}

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