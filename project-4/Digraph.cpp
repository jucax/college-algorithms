/* 
 * Add a description prior to each function, based on the information in the
 * header file and project instructions. 
 * Then fill in each function appropriately. 
 */

#include "Digraph.h"
#include <iostream>

/*
 * Adds a string representing the vertex to the set of vertices, it also initializes its edge list.
 */
void Digraph::addVertex(std::string vertex) {
    vertices.insert(vertex); // Add to the set
    edges[vertex] = std::list<DirectedEdge>(); // Add to map of edges with an empty list
}

/*
 * Adds a DirectedEdge from vertex v1 to v2 and assign the given weight to it.
 */
void Digraph::addDirectedEdge(std::string v1, std::string v2, int weight) {
    DirectedEdge edge = {v1, v2, weight}; // Create DirectedEdge
    edges[v1].push_back(edge); // Access to vertex edge list and add new edge
}

/*
 * Returns the list of DirectedEdges for the given vertex.
 */
std::list<DirectedEdge> Digraph::getEdges(std::string vertex) const {
    // .at() allow us to throw an exception if the list of that vertex doesn't exist 
    return edges.at(vertex); 
    // So we can be sure that something will be returned
}

/*
 * Returns the weight of the edge from vertex v1 to v2.
 * If the edge doesn't exist, it returns -1.
 */
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

/*
 * Prints all the vertices and their directed edges following the format specified.
 */
void Digraph::print() const {
    // Print list of vertices
    std::cout << "Vertices: ";
    for (const std::string& vertex : vertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    // Print list of directed edges
    std::cout << "Directed edges: " << std::endl;
    for (std::string vertex : vertices) { 
        const std::list<DirectedEdge>& edgeList = edges.at(vertex);            
        for (const DirectedEdge& edge : edgeList) {
            std::cout << edge.startVertex << " -> " << edge.endVertex << ": " << edge.weight << std::endl;
        }
    }
}

/*
 * Returns the set of the vertices in the graph.
 */
std::set<std::string> Digraph::getVertices() const {
   return vertices; // We can directly return the set
}