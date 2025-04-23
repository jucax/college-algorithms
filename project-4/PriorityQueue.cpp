/* 
 * Add a description prior to each function, based on the information in the
 * header file and project instructions. 
 * Then fill in each function appropriately. 
 * Use an iterator whenever traversing pq is required or appropriate. 
 */
#include "PriorityQueue.h"

/*
 * Inserts a new string s representing the vertex with the given priority into the multimap that represents the queue.
 */
void PriorityQueue::insert(std::string s, int priority) {
    pq.insert({priority, s}); // Insert pair into multimap
}

/*
 * Checks if the string s representing the vertex is already in the priority queue.
 */
bool PriorityQueue::contains(std::string s) {
    for (const auto& pair : pq) { // Traverse the multimap
        if (pair.second == s) { // Compare the second values (strings)
            return true;
        }
    }
    return false;
}

/*
 * Updates the priority of the string s representing the vertex by first removing the old pair. 
 * Then it inserts the new pair with the priority updated.
 */
void PriorityQueue::updatePriority(std::string s, int newpriority) {
   for (auto it = pq.begin(); it != pq.end(); ++it) { // Traverse the pq
        if ((*it).second == s) { //Compare second values until find the right vertex
            pq.erase(it); // Remove the old one
            break;        // Only remove one, there can be others with the same vertex
        }
    }

    // Insert new pair with the new priority
    pq.insert({newpriority, s});
}

/*
 * Returns the string representing the vertex with the lowest priority.
 * Then it removes it, to avoid double counting.
 * If the queue is empty, returns an empty string.
 */
std::string PriorityQueue::extractMin() {
    if (pq.empty()) return ""; // If empty, return ""

    auto smallest = pq.begin(); // Since the multimap sort the elements, the first one is the smallest

    std::string smallestItem = (*smallest).second; //Get item from that smallers pair 
    
    pq.erase(smallest); // We can remove this pair now
    return smallestItem;
}

/*
 * Returns if the priority queue is empty.
 */
bool PriorityQueue::isEmpty() const {
    return pq.empty(); // Use built-in method for multimap
}

/*
 * Prints the contents of the priority queue in priority order and following the format specified.
 */
void PriorityQueue::print() const {
    std::cout << "Priority Queue:" << std::endl;
    for (const auto& pair : pq) { // Print suggested format for debugging
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }
}