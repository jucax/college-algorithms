#include "HashSetSTL.h"
#include <unordered_set> // to use unordered_set
using namespace std;
#include <algorithm>
#include <iostream>

HashSetSTL::HashSetSTL()
{ }

int HashSetSTL::getSize() const {
    return hashSet.size();  // able to use size() from unordered_set 
}

int HashSetSTL::getTableSize() const {
    return hashSet.bucket_count();  // returns number of buckets in unordered_set
}

double HashSetSTL::getLoadFactor() const {
    return hashSet.load_factor();   // able to use load_factor() function from unordered_set (load_factor = size / bucket_count)
}

void HashSetSTL::printSet() const {
    for(int element : hashSet) {  // loop through each element of set
        cout << element << " ";
    }
}

void HashSetSTL::printTable() const {
    // prints an error message since unordered_set doesn't have the same details (i.e underlying lists) as separate chaining
    cout << "Error: unordered_set doesn't give us the details that we have for separate chaining" << endl;  }

int HashSetSTL::contains(int value) {
    // looks for value and returns iterator to it if found, otherwise it returns an iterator to the end() 
    //(the element past the end of the container).
    if(hashSet.find(value) == hashSet.end()) { 
        return -1;
    }
    else {
        unordered_set<int>::hasher fn = hashSet.hash_function();    // obtain hash function for our unordered set
        int hash = fn(value);   // calculate the hash based on the value 
        return hash;
    }
    
}

bool HashSetSTL::insert(int value) {
    if(contains(value) != -1) { // if value is already in set, can't insert
        return false; 
    }
    else {
        hashSet.insert(value);  // insert resizes automatically
        return true; 
    }
    return false;
}

bool HashSetSTL::remove(int value) {
    if(contains(value) == -1) { // if value isn't in set, can't remove
        return false; 
    }
    else {
        hashSet.erase(value); // use erase() to remove a value, handles resizing automatically
        return true;
    }
    return false;
}
