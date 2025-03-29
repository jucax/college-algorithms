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
    HashSetChaining();

/*
 * For any function below that does not have a comment, be sure to 
 * add one, perhaps using information from HashSet.h
 * You should rarely be duplicating those comments precisely, but instead
 * making sure they reflect the hash strategy of the class.
 */

    std::string getImplementationName() const { return "Chaining"; }
    
    int getSize() const;

    int getTableSize() const;

    double getLoadFactor() const;

/* 
 * Print the elements of the set, separated by spaces
 * For example, a possible output is:
 * 2 12 3 7 
 */
    void printSet() const;


/* 
 * Print the hash table contents, separated by spaces between buckets, noting 
 * the following:
 *   - for an empty bucket, display a hyphen, and nothing more
 *   - chained elements in a single bucket should be separated with ->
 * For example, this function could create output like:
 *     8 - 2->10 - - - 14 15
 */
    void printTable() const;

    int contains(int value);

/* 
 * Follow the specifications set forth in HashSet.h.
 * The newly inserted value should be at the end of the list on which it is placed.
 * Thus, if 2 and 12 were inserted into the same list, in that order, 
 * the output should represent that as 2->12, not 12->2.
 * As discussed in class, traversing the entire list may be necessary
 * since we do not keep multiple copies of the same value in a list. 
 */
    bool insert(int value);

    bool remove(int value);

  private:
    // The underlying hash table 
    std::vector<std::list<int>> hashTable;

    int computeHash(int value) const;
    void resizeTable(int newSize);
};