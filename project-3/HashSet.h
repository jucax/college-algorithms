 //The following line ensures that this header file is included only once.
#pragma once

#include <string>

/*
 * Virtual interface for a hash set class.
 * 
 * This object will contain a unique set of positive integers.
 * Items can be inserted/removed from the set with the insert and remove functions.
 *
 * If insert(value) is called with a value already in the set or remove(value) is
 * called with a value that is not in the set, the set will be unchanged. 
 * 
 * For example, the following sequence would result in the set that contains
 * two values {2, 3}, noting that the redundant insert of value 1 and removal of 
 * value 4 (which was never inserted) do not impact the set.
 *
 *      insert(1);
 *      insert(2);
 *      insert(3);
 *      insert(1);
 *      insert(2);
 *      remove(1);
 *      remove(4);
 *
 */
 
class HashSet {
  public:
    // return the name of the particular hashing strategy
    virtual std::string getImplementationName() const = 0;
    
    // return the number of values in the set
    virtual int getSize() const = 0;

    // return the size of the underlying hash table
    // details may depend may depend upon the particular hashing strategy
    virtual int getTableSize() const = 0;

    // return the load factor associated with this table 
    virtual double getLoadFactor() const = 0;

    // print the values in the set, separated by spaces, followed by a newline to std::cout    
    virtual void printSet() const = 0;
    
    // print all the values in the underlying hash table 
    // details may depend may depend upon the particular hashing strategy
    virtual void printTable() const = 0;

    // return the table location of value if the value is in the set
    // and return -1 if the value is not in the set
    virtual int contains(int value) = 0;

    // insert a value into the set, returning true if it is new to the current set
    // That is, the insertion resulted in one more value in the HashSet.
    // Before performing the insertion, rehash to double the table size if the 
    // load factor is strictly greater than MAX_LOAD_FACTOR
    virtual bool insert(int value) = 0;
    
    // remove a value from the set, returning true if the value was actually removed.
    // That is, if the value was not in the set, return false. 
    // Before performing the removal, rehash to half the table size if the 
    // load factor is strictly less than MIN_LOAD_FACTOR
    virtual bool remove(int value) = 0;
    
protected:
    // constants used by hashing strategies
    // Start with a small table to save memory when few elements are inserted
    int    const  INITIAL_HASHTABLE_SIZE = 2;
    // If more than 66% of the table is full, performance may drop due to collisions, 
    // so it is a good point to rehash the table
    double const  MAX_LOAD_FACTOR   = 0.66;
    // If less than 33% full, we shrink to avoid wasting space, so it is a good point 
    // to rehash the table
    double const  MIN_LOAD_FACTOR   = MAX_LOAD_FACTOR/2.0;

};