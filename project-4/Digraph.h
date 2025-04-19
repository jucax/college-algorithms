#ifndef DIGRAPH_
#define DIRAPH_H

#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

/*
 * A DirectedEdge in a graph consists of a start vertex and an end vertex,
 * both strings, and an integer weight. 
 */
struct DirectedEdge {
    std::string startVertex, endVertex;
    int weight;
};

/*
 * A Digraph stores a set of vertices, each denoted by a string, and 
 * an adjacency list of directed edges. A map associates each vertex with
 * a linked list of directed edges starting at that vertex.
 */
class Digraph {
public:
    // add a vertex to the digraph
    void addVertex(std::string vertex);                  
    // add a directed edge to the digraph
    void addDirectedEdge(std::string v1, std::string v2, int weight); 
    // get all directed edges that start at a given vertex in the digraph
    std::list<DirectedEdge> getEdges(std::string vertex) const;     
    // get the weight of a directed edge in the digraph
    int getWeight(std::string v1, std::string v2) const;     
    // get all vertices in the digraph
    std::set<std::string> getVertices() const;
    // print the graph in a specified format, per the assignment prompt
    void print() const;                             

private:
    std::set<std::string> vertices;           
    std::map<std::string, std::list<DirectedEdge>> edges;  
};

#endif