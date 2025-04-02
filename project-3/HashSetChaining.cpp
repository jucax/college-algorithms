#include "HashSetChaining.h"

#include <iostream>

HashSetChaining::HashSetChaining() :
    hashTable(INITIAL_HASHTABLE_SIZE)
{ }

int HashSetChaining::getSize() const {
    int count = 0;
    // Traverse the vector
    for (const std::list <int>& bucket : hashTable) {
        count += bucket.size(); // Add the sizes of every bucket
    }
    return count;
}

int HashSetChaining::getTableSize() const {
    return hashTable.size(); // Return quantity of buckets in the vector
}

double HashSetChaining::getLoadFactor() const {
    double elements = (double) getSize();  // Cast to double
    double size = (double) getTableSize();
    return elements / size; // Calculate and return load factor dividing the number of elements by the size of the table
}

void HashSetChaining::printSet() const {
    // Traverse the vector
    for (const std::list <int>& bucket : hashTable) {
        // Traverse each bucket
        for (int element : bucket){
            std::cout << element << " "; // Print elements next to each other
        }
    }
    std::cout << std::endl;
}

void HashSetChaining::printTable() const {
    // Traverse in the vector
    for (const std::list <int>& bucket : hashTable) {
        if (bucket.empty()) std::cout << "-";
        else {
            bool first = true; // Print -> before the elements, except for the first one 
            // Traverse in each bucket
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
    // Calculate the bucket to search in
    int index = computeHash(value);
    const std::list<int>& bucket = hashTable[index];

    // Traverse the bucket
    for (int element : bucket) {
        if (element == value) {
            return index;  // Found the value at this bucket
        }
    }

    return -1;  // Value not found
}

bool HashSetChaining::insert(int value) {
    // Check for load factor in case we need to rehash
    if (getLoadFactor() > MAX_LOAD_FACTOR) {
        resizeTable(hashTable.size() * 2);
    }

    // Check if value is in the set
    if (contains(value) != -1) {
        return false;
    }
    // Calculate the bucket to insert in
    int index = computeHash(value);
    hashTable[index].push_back(value);  // Add to the end 

    return true;
}

void HashSetChaining::resizeTable(int newSize) {
    std::vector<std::list<int>> newBiggerTable(newSize); // Create new list

    for (const std::list<int>& bucket : hashTable) {
        for (int element : bucket) {
            int newIndex = element % newSize;  // Calculate new hash index
            newBiggerTable[newIndex].push_back(element);
        }
    }

    hashTable = std::move(newBiggerTable);  // Replace tables
}

bool HashSetChaining::remove(int value) {
    // Calculate the bucket to search in
    int index = computeHash(value);
    std::list<int>& bucket = hashTable[index];

    // Traverse looking for the value
    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (*it == value) {
            bucket.erase(it);

            // Check for load factor in case we need to rehash
            if (getLoadFactor() < MIN_LOAD_FACTOR && hashTable.size() > INITIAL_HASHTABLE_SIZE) {
                resizeTable(hashTable.size() / 2);
            }

            return true;
        }
    }

    return false;
}

int HashSetChaining::computeHash(int value) const {
    // Hash function is modding by the table size, it ensures index stays in bounds.
    return value % hashTable.size();
}
