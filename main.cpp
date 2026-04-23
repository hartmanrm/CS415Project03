#include "StandardTrie.h"
#include "TernarySearchTree.h"

#include <iostream>
#include <fstream>
#include <cctype>

std::string prepString(std::string before){
    char currChar;
    std::string after = "";
    for (int i = 0; i < before.length(); i++){
        currChar = before[i];
        if (isalpha(currChar)){
            after += std::tolower(currChar);
        }
    }
    return after;
}



int main(int argc, char *argv[]){
    if (argc != 3){
        std::cout << "Error: Invalid number of arguements. \n" 
            << "Please provide 2 arguements: fileName and flag indicating how strings are searched";
    }
    std::string fileName = argv[1];
    std::string caseFlag = argv[2];

    std::ifstream inputFile("input/" + fileName);
    if (!inputFile.is_open()){
        std::cout << "Unable to open file " << fileName << " \n";
        return 1;
    }

    standardTrieNode* standardTrieRoot = new standardTrieNode();;
    ternaryTrieNode ternaryTrieObject;
    ternaryTrieNode* ternaryTrieRoot = nullptr;

    //insert into tries
    std::string currWord, cleanedWord;
    char currChar;
    // vector of all words to search for in case 2
    std::vector<std::string> allWords;

    while (inputFile >> currWord){
        //use prepString to get the cleaned version of the string to insert it, 
        cleanedWord = prepString(currWord);
        // insert into vector
        allWords.push_back(cleanedWord);
        // use the two insert functions to insert it into both of the tries
        standardTrieRoot->insert(standardTrieRoot, cleanedWord);
        const char* wordAsArr = cleanedWord.c_str();
        ternaryTrieObject.insert(&ternaryTrieRoot, wordAsArr);
    }

    // Moved into regular main function:
    // Case 1
    if (caseFlag == "1") {
        std::cout << "Time taken to build the standard Trie is " << standardTrieRoot->getBuildTime() << " and space occupied by it is " << standardTrieRoot->getTotalSpace() << "\n";
        std::cout << "Time taken to build the BST based Trie is " << ternaryTrieObject.getBuildTime() << " and space occupied by it is " << ternaryTrieObject.getTotalSpace() << "\n\n";
        
        std::cout << "Enter search string: ";
        std::string searchString;
        std::cin >> searchString;
        while (searchString != "exit") {
            // Standard Trie
            std::vector<std::string> printVector = standardTrieRoot->autocomplete(standardTrieRoot, searchString);
            std::cout << "Time taken to search in the standard Trie is " << standardTrieRoot->getSearchTime() << "\n";
            std::cout << "Auto-complete results using standard Trie are: ";
            if (standardTrieRoot->findPrefixNode(standardTrieRoot, searchString) == nullptr) {
                std::cout << "Word not found!";
            }
            else{
                for (int i=0; i<printVector.size(); i++) {
                    std::cout << printVector.at(i);
                    if (i != printVector.size()-1) {
                        std::cout << ", ";
                    }
                }
            }
            std::cout << "\n" << "Time taken to find auto-complete results in the standard Trie is " << standardTrieRoot->getAutoCompleteTime() << "\n\n";

            // BST Based Trie
            const char* prefixAsArr = searchString.c_str();
            
            printVector = ternaryTrieRoot->autocomplete(ternaryTrieRoot, searchString);
            std::cout << "Time taken to search in the BST based Trie is " << ternaryTrieRoot->getSearchTime() << "\n";
            std::cout << "Auto-complete results using BST based Trie are: ";
            if (ternaryTrieRoot->findPrefixNode(&ternaryTrieRoot, prefixAsArr) == nullptr) {
                std::cout << "Word not found!";
            }
            else{
                for (int i=0; i<printVector.size(); i++) {
                    std::cout << printVector.at(i);
                    if (i != printVector.size()-1) {
                        std::cout << ", ";
                    }
                }
            }
            std::cout << "\n" << "Time taken to find auto-complete results in the BST based Trie is " << ternaryTrieRoot->getAutoCompleteTime() << "\n\n";
            
            std::cout << "Enter search string: ";
            std::cin >> searchString;
        }
        std::cout << "\n Exiting... goodbye!\n";
        return 0;
    }

    // Case 2
    else if (caseFlag == "2") {
        std::cout << "Time taken to build the standard Trie is " << standardTrieRoot->getBuildTime() << " and space occupied by it is " << standardTrieRoot->getTotalSpace() << "\n";
        std::cout << "Time taken to build the BST based Trie is " << ternaryTrieObject.getBuildTime() << " and space occupied by it is " << ternaryTrieObject.getTotalSpace() << "\n\n";
        
        int StandardAllSearchTime = 0;
        int BSTAllSearchTime = 0;
        for (int i=0; i<allWords.size(); i++) {
            standardTrieRoot->findPrefixNode(standardTrieRoot, allWords.at(i));
            StandardAllSearchTime += standardTrieRoot->getSearchTime();
        }
        for (int i=0; i<allWords.size(); i++) {
            const char* prefixAsArr = allWords.at(i).c_str();
            ternaryTrieRoot->findPrefixNode(&ternaryTrieRoot, prefixAsArr);
            BSTAllSearchTime += ternaryTrieRoot->getSearchTime();
        }
        std::cout << "Time taken to search all the strings in the standard Trie is " << StandardAllSearchTime << "\n";
        std::cout << "Time taken to search all the strings in the BST based Trie is " << BSTAllSearchTime << "\n\n";
        return 0;
    }
}