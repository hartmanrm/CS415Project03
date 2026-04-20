#include "StandardTrie.h"
#include "TernarySearchTree.h"

#include <iostream>

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

int main(int argc, char *argv[]){
    if (argc != 3){
        std::cout << "Error: Invalid number of arguements. \n" 
            << "Please provide 2 arguements: fileName and flag indicating how strings are searched";
    }
    return 0;
}