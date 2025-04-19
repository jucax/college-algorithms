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

/*
 * Write an appropriate description of this function. 
 */ 

void dijkstra(const Digraph &g, std::string startv, std::string endv) {
    // shortest distance found so far
    std::map<std::string, int> distances;      
    // previous vertex in best path found so far
    std::map<std::string, std::string> previousVertex;    
    PriorityQueue pq;


    std::cout << "Run dijkstra " << startv << " " << endv << " " << g.getVertices().size() << std::endl;

    // Implement Dijkstra's algorithm here using the structures defined
    // above and the functionality in Digraph and PriorityQueue
   

    std::cout << std::endl << "Shortest path is:" << std::endl;
    // Print out the shortest path; match formatting

    std::cout << std::endl << "It has length: " << std::endl;
    // Print the length of the shortest path

    std::cout << "Final map of distances:" << std::endl;
    for (auto pair : distances){
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    std::cout << std::endl << "Final map of previous vertices:" << std::endl;
    for (auto pair : previousVertex) {
        std::cout << pair.first << ": " << pair.second << std::endl;
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


