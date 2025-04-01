#include "HashSetSTL.h"

#include <algorithm>
#include <iostream>

HashSetSTL::HashSetSTL(): 
    hashSet(INITIAL_HASHTABLE_SIZE)
{ }

int HashSetSTL::getSize() const {
    return hashSet.size(); // Use built-in method to get size
}

int HashSetSTL::getTableSize() const {
    return hashSet.bucket_count(); // Use built-in method to get bucket-size
}

double HashSetSTL::getLoadFactor() const {
    return hashSet.load_factor(); // Use built-in method to get load_factor
}

void HashSetSTL::printSet() const {
    for (int element : hashSet) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void HashSetSTL::printTable() const {
    std::cout << "Error: Detailed table structure is not available in std::unordered_set. Bucket-level access is not supported in this implementation" << std::endl; // std::unsorted_set is now able to present this details
}

int HashSetSTL::contains(int value) {
    if (hashSet.find(value) != hashSet.end()) { // If the set contains the value
        return hashSet.bucket(value);
    } else {
        return -1; // Not in the set
    }
}

bool HashSetSTL::insert(int value) {
    auto result = hashSet.insert(value); // Built-in method for insert already check for duplicates, and return a result
    return result.second;
}

bool HashSetSTL::remove(int value) {
    auto result = hashSet.erase(value); // Built-in method for erase already check for duplicates, and return a result
    return result == 1;
}
