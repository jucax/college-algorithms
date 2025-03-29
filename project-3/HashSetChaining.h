//The following line ensures that this header file is included only once.
#pragma once

#include "HashSet.h"

#include <list>
#include <vector>

/* 
 * A HashSet using the separate chaining strategy has a 
 * std::vector<std::list<int> > as the underlying hash table. 
 * The vector gives the buckets for the various values in the table,
 * each of which contains a doubly linked list from std::list
 */
class HashSetChaining : public HashSet {
  public:
    // Construct the hash set initializing an empty table of size INITIAL_HASHTABLE_SIZE
    // Initializes the hash table as a vector of empty lists.
    HashSetChaining();

/*
 * For any function below that does not have a comment, be sure to 
 * add one, perhaps using information from HashSet.h
 * You should rarely be duplicating those comments precisely, but instead
 * making sure they reflect the hash strategy of the class.
 */

    // Return the name of the particular hashing strategy, in this case Chaining
    std::string getImplementationName() const { return "Chaining"; }
    
     // Return the number of values in the set
     // Traverses each bucket (list) in the hash table,summing the size of each list
    int getSize() const;

    // Return the size of the underlying hash table
    // which in thie implementation is the size of the hashTable vector.
    int getTableSize() const;

    // Return the load factor associated with this table 
    // Using the getSize() and getTableSize() methods we can calculate it as stored elements divided by the number of buckets. 
    // Need to casts to double to ensure floating-point division.
    double getLoadFactor() const;

/* 
 * Print the elements of the set, separated by spaces
 * For example, a possible output is:
 * 2 12 3 7 
 */
    void printSet() const;


/* 
 * Print the hash table contents, separated by spaces between buckets, noting the following:
 *   - for an empty bucket, display a hyphen, and nothing more
 *   - chained elements in a single bucket should be separated with ->
 * For example, this function could create output like:
 *     8 - 2->10 - - - 14 15
 */
    void printTable() const;

    // return the table location of value if the value is in the set
    // and return -1 if the value is not in the set
    // Uses computeHash(value)to access the correct bucket, 
    // then searches through the list to check if the value exists in that bucket.
    int contains(int value);

/* 
 * Follow the specifications set forth in HashSet.h.
 * The newly inserted value should be at the end of the list on which it is placed.
 * Thus, if 2 and 12 were inserted into the same list, in that order, 
 * the output should represent that as 2->12, not 12->2.
 * As discussed in class, traversing the entire list may be necessary since we do not keep multiple copies of the same value in a list. 
 */
    bool insert(int value);


    bool remove(int value);

  private:
    // The underlying hash table 
    std::vector<std::list<int>> hashTable;

    // Returns the hash index for the given value using value % table size.
    // Ensures the value maps to a valid bucket in the hash table.
    int computeHash(int value) const;

    // Rehashes all elements into a new table of size newSize.
    // Each value is reinserted into the new table using value % newSize as the new hash formula 
    // To ensure each value is placed in a valid bucket for the resized table.
    void resizeTable(int newSize);
};