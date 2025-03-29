//The following line ensures that this header file is included only once.
#pragma once

#include "HashSet.h"

#include <unordered_set>

/*
 * A HashSetSTL uses the std::unordered_set to store the underlying data.
 * See details at https://en.cppreference.com/w/cpp/container/unordered_set
 */
class HashSetSTL : public HashSet {
  public:
  
/*
 * For any function below that does not have a comment, be sure to add one, perhaps using information from HashSet.h
 * You should rarely be duplicating those comments precisely, but instead making sure they reflect the hash strategy of the class.
 */

    // Construct the std::unordered_set hashSet initializing an empty table of size INITIAL_HASHTABLE_SIZE
    HashSetSTL();
    
    // Return the name of the particular hashing strategy, in this case STL  Unsorted Set
    std::string getImplementationName() const { return "STL Unordered Set"; }
  
    // Return the number of elements currently stored in the std::unordered_set hashSet.
    int getSize() const;

    // Return the size of the underlying hash table
    // It is the current number of buckets used by the underlying std::unordered_set.
    int getTableSize() const;

    // Return the load factor associated with this table
    // Retrieved directly using the built-in unordered_set::load_factor() method
    double getLoadFactor() const;

/* 
 * Print the elements of the set, separated by spaces
 * For example, a possible output is:
 * 2 12 3 7 
 */
    void printSet() const;

/*
 * Print an error message (using cout) that is informative to the user since std::unordered_set doesn't give us the details that we have for separate chaining so we shouldn't try to print out the details of the empty buckets
 */
    void printTable() const;

     // return the table location of value if the value is in the set
    // and return -1 if the value is not in the set
    // Uses .find() to check if the set contains the value,
    // and if it does .bucket() to return the location
    int contains(int value);

    // insert a value into the set, returning true if it is new to the current set
    // Uses .insert(), which places the valueinto an appropriate bucket and return a pair with a boolean value indicating if it was a succesfull insertion or not.
    // Rehashing is handled automatically by the std::unordered_set
    bool insert(int value);

    // remove a value from the set, returning true if the value was actually removed.
    // Uses .erase(), which removes the value if found and returns the number of elements erased (0 or 1).
    // std::unordered_set does not automatically shrink, 
    // and we do not perform manual rehashing in this implementation.
    bool remove(int value);

  private:
    std::unordered_set<int> hashSet;
};