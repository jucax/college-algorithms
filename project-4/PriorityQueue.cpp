/* 
 * Add a description prior to each function, based on the information in the
 * header file and project instructions. 
 * Then fill in each function appropriately. 
 * Use an iterator whenever traversing pq is required or appropriate. 
 */
#include "PriorityQueue.h"

void PriorityQueue::insert(std::string s, int priority) {
    pq.insert({priority, s}); //Insert into multimap
}

bool PriorityQueue::contains(std::string s) {
    for (const auto& pair : pq) { // Traverse the multimap
        if (pair.second == s) { // Compare the second values (strings)
            return true;
        }
    }
    return false;
}

void PriorityQueue::updatePriority(std::string s, int newpriority) {
   for (auto it = pq.begin(); it != pq.end(); ++it) { // Traverse the pq
        if ((*it).second == s) { //Compare second values until find the right vertex
            pq.erase(it); // Erase the old one
            break;        // Only remove one, there can be others with the same vertex
        }
    }

    // Insert again with the new priority
    pq.insert({newpriority, s});
}

std::string PriorityQueue::extractMin() {
    if (pq.empty()) return ""; // Empty case

    auto smallest = pq.begin(); // Since the multimap sort the elements, the first one is the smallest

    std::string smallestItem = (*smallest).second; //Get item from that smallers pair 
    
    pq.erase(smallest); // We can remove this pair now

    return smallestItem;
}

bool PriorityQueue::isEmpty() const {
    return pq.empty(); // Use built-in method for multimap
}

void PriorityQueue::print() const {
    std::cout << "Priority Queue:" << std::endl;
    for (const auto& pair : pq) { // Print suggested format for debugging
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}