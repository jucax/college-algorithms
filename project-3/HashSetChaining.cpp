#include "HashSetChaining.h"

#include <iostream>

HashSetChaining::HashSetChaining() :
    hashTable(INITIAL_HASHTABLE_SIZE)
{ }

int HashSetChaining::getSize() const {
    int count = 0;
    for (const std::list <int>& bucket : hashTable) {
        count += bucket.size();
    }
    return count;
}

int HashSetChaining::getTableSize() const {
    return hashTable.size();
}

double HashSetChaining::getLoadFactor() const {
    return static_cast<double>(getSize() / getTableSize());
}

void HashSetChaining::printSet() const {
    for (const std::list <int>& bucket : hashTable) {
        for (int element : bucket){
            std::cout << element << " ";
        }
    }
    std::cout << std::endl;
}

void HashSetChaining::printTable() const {
    for (const std::list <int>& bucket : hashTable) {
        if (bucket.empty()) std::cout << "-";
        else {
            bool first = true; // Print -> before the elements, except for the first one 
            for (int element : bucket) {
                if (!first) std::cout << "->";
                std::cout << element;
                first = false;
            }
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

int HashSetChaining::contains(int value) {
    int index = computeHash(value);
    const std::list<int>& bucket = hashTable[index];

    for (int element : bucket) {
        if (element == value) {
            return index;  // Found the value at this bucket
        }
    }

    return -1;  // Value not found
}

bool HashSetChaining::insert(int value) {
    // Check if value is in the set
    if (contains(value) != -1) {
        return false;
    }

    // Check for load factor in case we need to rehash
    if (getLoadFactor() > MAX_LOAD_FACTOR) {
        resizeTable(hashTable.size() * 2);
    }

    int index = computeHash(value);
    hashTable[index].push_back(value);  // Add to the end 

    return true;
}

void HashSetChaining::resizeTable(int newSize) {
    std::vector<std::list<int>> newBiggerTable(newSize);

    for (const std::list<int>& bucket : hashTable) {
        for (int element : bucket) {
            int newIndex = element % newSize;  // Calculate new hash index
            newBiggerTable[newIndex].push_back(element);
        }
    }

    hashTable = std::move(newBiggerTable);  // Replace tables
}

bool HashSetChaining::remove(int value) {
    int index = computeHash(value);
    std::list<int> &bucket = hashTable[index];

    // Check for load factor in case we need to rehash
    if (getLoadFactor() < MIN_LOAD_FACTOR && hashTable.size() > INITIAL_HASHTABLE_SIZE) {
        resizeTable(hashTable.size() / 2);
    }

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (*it == value) { // Dereference and check if it matches
            bucket.erase(it);
            return true;
        }
    }
    return false;
}

int HashSetChaining::computeHash(int value) const {
    return value % hashTable.size();
}
