#include "HashSetChaining.h"

#include <iostream>

HashSetChaining::HashSetChaining() :
    hashTable(INITIAL_HASHTABLE_SIZE)
{ }

int HashSetChaining::getSize() const {
    return -1;
}

int HashSetChaining::getTableSize() const {
    return -1;
}

double HashSetChaining::getLoadFactor() const {
    return -1.0;
}

void HashSetChaining::printSet() const {

}

void HashSetChaining::printTable() const {
    
}

int HashSetChaining::contains(int value) {
    return -1;
}

bool HashSetChaining::insert(int value) {
    return false;
}

void HashSetChaining::resizeTable(int newSize) {

}

bool HashSetChaining::remove(int value) {
    return false;
}

int HashSetChaining::computeHash(int value) const {
    return -1;
}
