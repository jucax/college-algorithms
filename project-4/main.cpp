// Make changes ONLY within the dijkstra function. 
// Keep the provided print statements. 

#include <iostream>
#include <fstream>
#include <sstream>
#include "Digraph.h"
#include "PriorityQueue.h"

/*
 * Creates a vector of strings from the lines of input, tokenized by spaces.
 */ 
std::vector<std::string> split(const std::string &s, char separator) {
    std::stringstream ss(s);  
    std::string item;
    std::vector<std::string> values;
    while (getline(ss, item, separator)) {
        values.push_back(item);
    }
    return values;
}

/**
 * This function runs Dijkstra's algorithm to find the shortest path from a start vertex to an end vertex.
 * It works on a directed or undirected graph.
 * 
 * It follows four main phases:
 * - Initialization: sets initial distances, previous vertex map, and fills the priority queue.
 * - Execution: repeatedly process the closest unvisited vertex and updates distances to neighbors.
 * - Postprocessing: rebuilds the shortest path from start to end using.
 * - Printing: displays the path, total length, and the final state of distances.
 * 
 * @param g       The digraph containing vertices and weighted edges
 * @param startv  The string representing the starting vertex
 * @param endv    The string representing the ending vertex 
 */

void dijkstra(const Digraph &g, std::string startv, std::string endv) {
    // INITIALIZATION PHASE
        // Shortest distance found so far
        std::map<std::string, int> distances;  
        for (const std::string vertex : g.getVertices()) { // For each vertex in the Digraph
            if (vertex == startv) {
                distances[vertex] = 0; // The distances for the first node is 0
            } else {
                distances[vertex] = 1000000; // This represents and infinite distances for the rest of the nodes
            }
        }    

        // Previous vertex in best path found so far
        std::map<std::string, std::string> previousVertex; 

        // Add vertices to priority queue   
        PriorityQueue pq;
        for (const std::string vertex : g.getVertices()) { // For each vertex in the Digraph
            pq.insert(vertex, distances[vertex]); // Using the function we implemented
        }    

    // EXECUTION PHASE
        std::cout << "Run dijkstra " << startv << " " << endv << " " << g.getVertices().size() << std::endl;

        // Implement Dijkstra's algorithm here using the structures defined
        // above and the functionality in Digraph and PriorityQueue
        while (!pq.isEmpty()) {
            
            std::string minVertex = pq.extractMin(); // Visit first in the priority queue

            std::cout << "Visiting vertex " << minVertex << std::endl;

            // Avoid process neighbors if we've reached the end vertex
            if (minVertex == endv) {
                continue;
            }

            for (const DirectedEdge& edge : g.getEdges(minVertex)) {
                std::string neighborVertex = edge.endVertex; // Get the neighbor of the vertex we are visiting
                int weight = edge.weight;
            
                // Print the vertex that we just checked
                std::cout << "End vertex: " << neighborVertex << std::endl;
                // Add that weight to the provious distance accumulated
                int updatedDistance = distances[minVertex] + weight; 

                // If the new distance is better than the other alternaticves, then we update the priority queue
                if (pq.contains(neighborVertex) && updatedDistance < distances[neighborVertex]) { 
                    std::cout << "  Updating distances[" << neighborVertex << "] from "
                            << distances[neighborVertex] << " to " << updatedDistance << std::endl;

                    // Update distances
                    distances[neighborVertex] = updatedDistance;
                    previousVertex[neighborVertex] = minVertex;
                    pq.updatePriority(neighborVertex, updatedDistance);
                }
            }
        }
   
    // POSTPROCESSING PHASE
        // Create helper variables
        std::vector<std::string> path;
        std::string currentVertex = endv;

        // Calculate shortest path
        // Loop until we reach the start vertex
        while (currentVertex != startv && previousVertex.find(currentVertex) != previousVertex.end()) {
            path.push_back(currentVertex);
            currentVertex = previousVertex[currentVertex];
        }

        path.push_back(startv); // Include the start vertex at the end
        std::reverse(path.begin(), path.end()); // Reverse to get the normal direction

    // PRINTING PHASE
        std::cout << std::endl << "Shortest path is:" << std::endl;

        // Print the shortest path, matching the format
        for (const std::string& vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;

        // Print the length of the shortest path
        std::cout << std::endl << "It has length: " << distances[endv] << std::endl;

        std::cout << "Final map of distances:" << std::endl;
        // Print the map of distances, matching the format
        for (auto pair : distances){
            std::cout << pair.first << ": " << pair.second << std::endl;
        }

        std::cout << std::endl << "Final map of previous vertices:" << std::endl;
         // Print the map of previous vertices, matching the format
        for (const std::string& vertex : g.getVertices()) {
            std::cout << vertex << ": ";
            if (previousVertex.find(vertex) != previousVertex.end()) {
                std::cout << previousVertex[vertex];
            }
            std::cout << std::endl;
        }
}

/*
 * Prompts the user for a filename, reads in the file, and runs
 * Dijkstra's algorithm on the file, which prints the input graph and results.
 * All graphs are treated as directed graphs, so undirected graphs
 * simply have directed edges in both directions for an undirected edge.
 */ 
int main() {
    std::string filename;
    std::cout << "Enter the filename\n";
    std::cin >> filename;
    std::ifstream fin("Root/" + filename);
    if (fin.fail()) {
        std::cerr << "Could not open file. Exiting." << std::endl;
        exit(1);
    }

    std::string line;
    bool directed;
    Digraph g;

    while (getline(fin, line)) {
        std::stringstream mystream(line);
        std::vector<std::string> words;
        std::string tmp;
        while  (mystream >> tmp)
            words.push_back(tmp);

        
        if (words[0] == "undirected") {
            directed = false;
        } else if (words[0] == "directed") {
            directed = true;
        } else if (words[0] == "vertex") {
            g.addVertex(words[1]);
        } else if (words[0] == "edge") {
            g.addDirectedEdge(words[1], words[2], stoi(words[3]));
            if (!directed)
                g.addDirectedEdge(words[2], words[1], stoi(words[3]));
        } else if (words[0] == "dijkstra") {
            std::cout << std::endl; 
            g.print(); 
            std::cout << std::endl;
            dijkstra(g, words[1], words[2]);
        }
    }

    fin.close();
}


