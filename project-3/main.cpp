#include "HashSet.h"
#include "HashSetSTL.h"
#include "HashSetChaining.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

/**
 * This function reads a text file line by line, where each line starts with either
 * 'i' for insert or 'r' for remove, followed by the number. These operations are 
 * performed on the given hashSet implementation. If debug is true, the function prints
 * extra info after each insertion or deletion.
 * 
 * @param hashSet The HashSet implementation to test (STL or chaining).
 * @param filename The name of the text file with the operations.
 * @param debug If true, print extra debug information.
 */

void testHash(HashSet & hashSet, std::string filename, bool debug) {
    std::ifstream fin(filename);

    // Read each of the operations and print extra information if debug is true
    char c;
    int value;
    while (fin >> c >> value) {
        if (c == 'i') {
            if (debug)
                std::cout << "Insert " << value << std::endl; // Show insertion element by element
            hashSet.insert(value);
        }
        else if (c == 'r') {
            if (debug)
                std::cout << "Remove " << value << std::endl; // Show deletion element by element
            hashSet.remove(value);
        }
        if (debug)
            hashSet.printTable();
    }
    
    // Print header
    std::cout << "---=== Hashing " << filename << " with " << hashSet.getImplementationName() << " ===---" << std::endl;
    std::cout << "   Number of Elements: " << hashSet.getSize() << std::endl;
    std::cout << "           Table Size: " << hashSet.getTableSize() << std::endl;
    std::cout << "          Load Factor: " << std::setprecision(3) << hashSet.getLoadFactor() << std::endl;

    // Print set and table
    if (hashSet.getSize() < 20) {
        std::cout << "     Set elements: ";
        hashSet.printSet();
        std::cout << "   Table elements: ";
        hashSet.printTable();
    }
    std::cout << std::endl;
    
    // Print T or F table
    std::cout << " Checking contains() for values from 1 to 100:" << std::endl;
    
    // Check contains() for first 100 positive integers, a reasonable sample range.
    for (int i=1; i<=100; ++i) {
        if (i%10 == 1)
            std::cout << "      ";
        std::cout << ((hashSet.contains(i) != -1) ? "T" : "F") << " ";
        if (i%10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * This function checks if both hash sets contain the same elements from 1 to 1000. 
 * If any value is in one but not the other, it prints a message pointing to the mismatch.
 * If all the values are the same, it prints a message to confirm consistency.
 * 
 * @param hs1 The first hash set.
 * @param hs2 The second hash set.
 */

void checkSetsAreTheSame(HashSet & hs1, HashSet & hs2) {
    bool anyFailed = false;
    // Traverse the first 1000 elements of each hash set
    for (unsigned i=1; i<=1000; ++i) {
        bool contains1 = (hs1.contains(i) != -1);
        bool contains2 = (hs2.contains(i) != -1);

        // Report if there is a mismatch
        if (contains1 != contains2) {
            std::cout << "Hash sets do not agree for the value " << i << ": " << contains1 << " " << contains2 << std::endl;
            anyFailed = true;
        }
    }
    
    // Report if both sets have the same numbers
    if (!anyFailed)
        std::cout << "Hash sets are consistent for the considered values" << std::endl;
}

/**
 * This function tests the same text file on both STL and Chaining implementations,
 * prints the info, with or without debug extra info, and then checks that both 
 * implementations give the same results.
 * 
 * @param filename The name of the text file to test with.
 * @param debug If true, enables debug output while testing.
 */

void runHashTest(std::string filename, bool debug) {
    HashSetSTL hsstl;
    testHash(hsstl, filename, debug);

    HashSetChaining hsc;
    testHash(hsc, filename, debug);
    
    checkSetsAreTheSame(hsstl, hsc);
    
}

/**
 * Runs the hash test on the file specified, and with the debug mode on or off
 */

int main() {
    runHashTest("data.txt", false);
    return 0;
}