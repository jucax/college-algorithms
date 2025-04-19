#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

/*
 * A priority queue where the keys are the priorities and the values are the strings. 
 * Use a multimap which is similar to a map but permits multiple values per key.
 */

#include <iostream>
#include <map>
#include <string>


class PriorityQueue {
public:
    // add a new item into the priority queue
    void insert(std::string s, int priority);    
    // determine if the given string is already in the priority queue
    bool contains(std::string s);  
    // update the priority of an item already in the priority queue
    void updatePriority(std::string s, int newpriority); 
    // return the item with the minimum priority
    std::string extractMin(); 
    // determine if the priority queue is empty
    bool isEmpty() const;   
    // print the items in the priority queue and their priorities
    // in the format specified in the assignment prompt
    void print() const;

private:
    std::multimap<int, std::string> pq;
};

#endif