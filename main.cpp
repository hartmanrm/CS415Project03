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

    //REGINA SLOP
    std::cout << "STANDARD\n" << std::endl;
    standardTrieRoot->print(standardTrieRoot);
    std::cout << "\n \n TERNARY\n" << std::endl;
    ternaryTrieObject.print(ternaryTrieRoot);

    std::cout <<  "\nStandard build time: " << standardTrieRoot->getBuildTime();
    std::cout <<  "\nStandard space: " << standardTrieRoot->getTotalSpace();
    std::cout <<  "\n\nTernary build time: " << ternaryTrieObject.getBuildTime();
    std::cout <<  "\n Ternary space: " << ternaryTrieObject.getTotalSpace() << "\n";
    return 0;
}

// Slightly less slop
int actualMain() {
    // Case 1
    //if (caseFlag == 1) {
        std::cout << "Time taken to build the standard Trie is " << "STANDARD TIME VARIABLE" << "and space occupied by it is " << "STANDARD SPACE VARIABLE" << std::endl;
        std::cout << "Time taken to build the BST based Trie is " << "BST TIME VARIABLE" << "and space occupied by it is " << "BST SPACE VARIABLE" << "\n\n";
        
        std::cout << "Enter search string: ";
        std::string searchString;
        std::cin >> searchString;
        while (searchString != "") {
            // Standard Trie
            std::cout << "Time taken to search in the standard Trie is " << "STANDARD SEARCH TIME VARIABLE" << "\n";
            std::cout << "Auto-complete results using standard Trie are: ";
            std::vector<std::string> printVector /* = standardTrieRoot->autocomplete(standardTrieRoot, searchString) */;
            for (int i=0; i<printVector.size(); i++) {
                std::cout << printVector.at(i);
                if (i != printVector.size()-1) {
                    std::cout << ", ";
                }
            }
            std::cout << "Time taken to find auto-complete results in the standard Trie is " << "STANDARD AUTO-COMPLETE TIME" << "\n";

            // BST Based Trie
            std::cout << "Time taken to search in the BST based Trie is " << "BST SEARCH TIME VARIABLE" << "\n";
            std::cout << "Auto-complete results using BST based Trie are: ";
            // printVector = ternaryTrieRoot->autocomplete(ternaryTrieRoot, searchString);
            for (int i=0; i<printVector.size(); i++) {
                std::cout << printVector.at(i);
                if (i != printVector.size()-1) {
                    std::cout << ", ";
                }
            }
            std::cout << "Time taken to find auto-complete results in the BST based Trie is " << "BST AUTO-COMPLETE TIME" << "\n";
        }
    //}

    /*
    if (caseFlag == 2) {
        std::cout << "Time taken to build the standard Trie is " << "STANDARD TIME VARIABLE" << " and space occupied by it is " << "STANDARD SPACE VARIABLE" << "\n";
        std::cout << "Time taken to build the BST based Trie is " << "BST TIME VARIABLE" << " and space occupied by it is " << "BST SPACE VARIABLE" << "\n";
        
        int StandardAllSearchTime = 0;
        int BSTAllSearchTime = 0;
        for (int i=0; i<allWords.size(); i++) {
            standardTrieRoot->findPrefixNode(standardTrieRoot, allWords.at(i));
            
        }
    }
    */


    
    return 0;
}