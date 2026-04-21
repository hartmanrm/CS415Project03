#include "StandardTrie.h"
#include "TernarySearchTree.h"

#include <iostream>
#include <fstream>
#include <cctype>

/*
Open file
Read file word by word ignoring spaces
Ignore punctuation and make everything lowercase
    Insert word into Trie
    Calculate space needed for each implementation
Calculate time taken to build Trie
Print info

Autocomplete
    print every potential word that uses the prefix
    calculate search time
    calculate time to find autocomplete

*/
std::string prepString(std::string before){
    char currChar;
    std::string after = "";
    for (int i = 0; i < before.length(); i++){
        currChar = before[i];
        if (isalpha(currChar)){
            after += std::tolower(currChar); // WARNING to lower might return an int? make sure to check that later
        }
    }
    return after;
}



int main(int argc, char *argv[]){
    if (argc != 3){
        std::cout << "Error: Invalid number of arguements. \n" 
            << "Please provide 2 arguements: fileName and flag indicating how strings are searched";
    }

    std::string fileName = argv[2];
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()){
        std::cout << "Unable to open file " << fileName << " \n";
        return 1;
    }

    //insert into tries
    std::string currWord;
    char currChar;
    while (inputFile >> currWord){
        //use prepString to get the cleaned version of the string to insert it, 
        // use the two insert funtions to insert it into both of the tries

    }

    return 0;
}