/* 
 * Add a description prior to each function, based on the information in the
 * header file and project instructions. 
 * Then fill in each function appropriately. 
 */

#include "Digraph.h"
#include <iostream>

void Digraph::addVertex(std::string vertex) {
    vertices.insert(vertex); // Add to the set
    edges[vertex] = std::list<DirectedEdge>(); // Add to map of edges with an empty list

}

void Digraph::addDirectedEdge(std::string v1, std::string v2, int weight) {
    DirectedEdge edge = {v1, v2, weight}; // Create DirectedEdge
    edges[v1].push_back(edge); // Access to vertex edge list and add new edge
}

std::list<DirectedEdge> Digraph::getEdges(std::string vertex) const {
    return edges.at(vertex); // .at() allow us to throw an exception if the list of that vertex doesn't exist 
    // So we can be sure that something will be returned
}

int Digraph::getWeight(std::string v1, std::string v2) const {
    // Access v1's edges list
    const std::list<DirectedEdge>& edgeList = edges.at(v1);

    // Look for edge that connects to v2
    for (const DirectedEdge& edge : edgeList) {              
        if (edge.endVertex == v2) {
            return edge.weight; // If we found it, return the weight value
        }
    }

    // Return -1 in case the edge doesn't exist
    return -1;
}

void Digraph::print() const {
    // Print list of vertices
    std::cout << "Vertices: ";
    for (const std::string& vertex : vertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    // Print directed edges
    std::cout << "Directed edges: " << std::endl;
    for (std::string vertex : vertices) { 
        const std::list<DirectedEdge>& edgeList = edges.at(vertex);            
        for (const DirectedEdge& edge : edgeList) {
            std::cout << edge.startVertex << " -> " << edge.endVertex << ": " << edge.weight << std::endl;
        }
    }
}

std::set<std::string> Digraph::getVertices() const {
   return vertices;
}