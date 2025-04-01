#include "HashSetChaining.h"
using namespace std;
#include <iostream>
#include <set>  // to use set 

HashSetChaining::HashSetChaining() :
    hashTable(INITIAL_HASHTABLE_SIZE)
{ }

int HashSetChaining::getSize() const {
    set<int> hashSet;       // use a set as the underlying data structure since we can utilize insert() 
    for(int i = 0; i < hashTable.size(); i++) {
        list<int> bucket = hashTable[i];    // lets us go through each bucket
            for(int number : bucket) {  
                hashSet.insert(number);  // insert() prevents duplicates from ever occuring since we are using a set
            }
    }
    return hashSet.size(); 
    
}

int HashSetChaining::getTableSize() const {
    return hashTable.size();
}

double HashSetChaining::getLoadFactor() const {
    double elements = (double) getSize();   // had to convert to double in order to get decimal value 
    double size = (double) getTableSize();
    return elements / size; // load factor is the ratio of number of elements and hash table size
}

void HashSetChaining::printSet() const {
    set<int> hashSet;   // use a set to be able to insert unique values
    
    // loop through each individual bucket to insert values from list
    for(int i = 0; i < hashTable.size(); i++) {
        list<int> bucket = hashTable[i];
        for(int number : bucket) {
            hashSet.insert(number);
        }
    }
    // print out elements from set
    for(int element : hashSet) {
        cout << element << " ";
    }
                
}

void HashSetChaining::printTable() const {
    // loop through each bucket
    for(int i = 0; i < hashTable.size(); i++) {
        list<int> bucket = hashTable[i];
        if(bucket.empty()) {
            cout << "- ";   // hyphen represents empty bucket
        }
        else {
            for(int number : bucket) {   // loops through each number of list
                cout << number;  // print out number  
                cout << "->";   // print out arrow to indicate chaining
            }
            
            // once done printing out elements of list, print out actual bucket value
            cout << computeHash(bucket.front()); // compute hash of first element of list in order to get bucket value
            cout << " ";
        }
    }
    cout << "" << endl; // for formatting purposes in output
}

int HashSetChaining::contains(int value) {
    int hash = computeHash(value);
    if(hash > hashTable.size() - 1) { // if hash of value is out of bounds, it's for sure not in the set
        return -1;
    }
    list<int> bucket = hashTable[hash]; // isolate bucket for which the value is supposed to be in
    for(int number : bucket) {
        if(number == value) {
            return hash;    // if found, return bucket value 
        }
    }
    return -1;
}

bool HashSetChaining::insert(int value) {
    // rehash to double the table size if the load factor is strictly greater than MAX_LOAD_FACTOR
    if(getLoadFactor() > MAX_LOAD_FACTOR) {
        resizeTable(getTableSize() * 2);
    }
    // if value is already in the set, you can't insert
    if(contains(value) != -1) {
        return false;
    }
    
    int hash = computeHash(value);  // get bucket of where value should be inserted based on hash function
    if(hash > hashTable.size() - 1 || contains(value) != -1) {   // if this hash is beyond bound or value is already in set, cannot insert
        return false;
    }
    else {
        hashTable[hash].push_back(value);   // insert into underlying list of corresponding bucket
        if(getLoadFactor() > MAX_LOAD_FACTOR) { // check again if the load factor goes beyond threshold
            resizeTable(getTableSize() * 2);
        }
        return true;
    }
    return false;
}

void HashSetChaining::resizeTable(int newSize) {
    vector<list<int> > resizedHashTable(newSize);   // create a list of the new size
    
    // loop through each bucket of original hashTable
    for(int i = 0; i < hashTable.size(); i++) {
        list<int> bucket = hashTable[i];
        for(int number : bucket) {
            int hash = number % newSize; // rehash each value in each list
            resizedHashTable[hash].push_back(number);    // push them back into their corresponding bucket
        }
            
    }
    hashTable = resizedHashTable;   // set our original hash table equal to the resized one just created 
}

bool HashSetChaining::remove(int value) {
    // rehash to half the table size if the load factor is strictly less than MIN_LOAD_FACTOR
    if(getLoadFactor() < MIN_LOAD_FACTOR) {
        resizeTable(getTableSize() / 2);
    }
    // if value is not in the set, you can't remove it
    if(contains(value) == -1) {
        return false;
    }
    else {
        int hash = computeHash(value);  // get bucket of where value should be based on hash function
        hashTable[hash].remove(value);  // removes from the underlying corresponding list
        if(getLoadFactor() < MIN_LOAD_FACTOR) { // check if remove makes load factor go below threshold
            resizeTable(getTableSize() / 2);
        }
        return true;
    }
    
    return false;
}

int HashSetChaining::computeHash(int value) const {
    return value % getTableSize();  // hash function is modding by the table size
}
