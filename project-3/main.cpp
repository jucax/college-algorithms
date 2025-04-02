#include "HashSet.h"
#include "HashSetSTL.h"
#include "HashSetChaining.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

/*
 * Be sure to add appropriate comments for each function in this file.
 */ 

void testHash(HashSet & hashSet, std::string filename, bool debug) {
    std::ifstream fin(filename);

    char c;
    int value;
    while (fin >> c >> value) {
        if (c == 'i') {
            if (debug)
                std::cout << "Insert " << value << std::endl;
            hashSet.insert(value);
        }
        else if (c == 'r') {
            if (debug)
                std::cout << "Remove " << value << std::endl;
            hashSet.remove(value);
        }
        if (debug)
            hashSet.printTable();
    }
    
    std::cout << "---=== Hashing " << filename << " with " << hashSet.getImplementationName() << " ===---" << std::endl;
    std::cout << "   Number of Elements: " << hashSet.getSize() << std::endl;
    std::cout << "           Table Size: " << hashSet.getTableSize() << std::endl;
    std::cout << "          Load Factor: " << std::setprecision(3) << hashSet.getLoadFactor() << std::endl;

    if (hashSet.getSize() < 20) {
        std::cout << "     Set elements: ";
        hashSet.printSet();
        std::cout << "   Table elements: ";
        hashSet.printTable();
    }
    std::cout << std::endl;
    
    std::cout << " Checking contains() for values from 1 to 100:" << std::endl;
    for (int i=1; i<=100; ++i) {
        if (i%10 == 1)
            std::cout << "      ";
        std::cout << ((hashSet.contains(i) != -1) ? "T" : "F") << " ";
        if (i%10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

void checkSetsAreTheSame(HashSet & hs1, HashSet & hs2) {
    bool anyFailed = false;
    for (unsigned i=1; i<=1000; ++i) {
        bool contains1 = (hs1.contains(i) != -1);
        bool contains2 = (hs2.contains(i) != -1);

        if (contains1 != contains2) {
            std::cout << "Hash sets do not agree for the value " << i << ": " << contains1 << " " << contains2 << std::endl;
            anyFailed = true;
        }
    }
    
    if (!anyFailed)
        std::cout << "Hash sets are consistent for the considered values" << std::endl;
}

void runHashTest(std::string filename, bool debug) {
    HashSetSTL hsstl;
    testHash(hsstl, filename, debug);

    HashSetChaining hsc;
    testHash(hsc, filename, debug);
    
    checkSetsAreTheSame(hsstl, hsc);
    
}


int main() {
    runHashTest("data.txt", false);
    return 0;
}