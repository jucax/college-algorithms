ALGORITHMS PROJECT 4 README
Student:
    Juan Martinez

Files submitted:
    - main.cpp – Main program that reads a graph input file (directed or undirected), constructs the graph using the Digraph class, and runs Dijkstra’s algorithm between two specified vertices. It reports a detailed output of Dijkstra’s progress and results​.
    - Digraph.h – Interface for the Digraph class, it defines the structure for representing a graph using adjacency lists and includes necessary public functions.
    - PriorityQueue.h – Interface for the PriorityQueue class. This class uses a multimap to support priority based retrieval. It includes necessary public functions.
    - Digraph.cpp – Implements all functions defined in Digraph interface. This includes adding vertices and edges, printing the graph, retrieving edges, and accessing weights between vertices. 
    - PriorityQueue.cpp – Implements all functions declared in PriorityQueue interface. These include inserting elements, checking for containment, updating priorities, extracting the element with minimum priority, and printing the contents of the queue. 
    - providedgraph1.txt – Test graph file 1 (undirected) with 6 vertices. Dijkstra’s algorithm is run from vertex a to d. 
    - providedgraph2.txt – Test graph file 2 (undirected) with Texas city names as vertices. Dijkstra’s algorithm is run from amarillo to houston​.
    - providedgraph3.txt – Test graph file 3 (directed) with 8 vertices. Dijkstra’s algorithm is run from s to t, verifying behavior with a more complex structure​.
    - providedgraph4.txt – Test graph file 4 (undirected) with 5 vertices and a range of edge weights. Dijkstra’s algorithm is run from vertex a to d.

High-Level Overview:
    Digraph.cpp: 
        1. addVertex() method
            Adds a new vertex to the graph.
            Inserts the vertex into the set of vertices and initializes an empty list in the adjacency map to store outgoing edges from that vertex.

            Efficiency Considerations:
                - Time Complexity: O(1), for insertion into std::set and std::map
                - Space Complexity: O(1) per vertex added.

        2. addDirectedEdge() method
            Adds a DirectedEdge from vertex v1 to v2 and assign the given weight to it.
            Creates a DirectedEdge struct and appends it to the list of edges corresponding to v1 in the adjacency map.

            Efficiency Considerations:
                - Time Complexity: O(1), for insertion into the list of edges.
                - Space Complexity: O(1) per edge added.

        3. getEdges() method
            Returns the list of DirectedEdges for the given vertex.
            Accesses the adjacency map using .at() which throws an exception if the vertex does not exist, ensuring safe access.

            Efficiency Considerations:
                - Time Complexity: O(1), for access to map and return of reference.
                - Space Complexity: O(1), a reference to existing data.
            
        4. getWeight() method
            Returns the weight of the edge from vertex v1 to v2.
            Searches through the list of outgoing edges from v1 to find one where the end vertex is v2.
            Efficiency Considerations:
                - Time Complexity: O(n), where n is the number of outgoing edges from v1
                - Space Complexity: O(1), no extra storage used.

        5. print() method
            Prints all the vertices and their directed edges following the format specified.
            Used for debugging and verifying graph structure before running Dijkstra’s algorithm.
            Efficiency Considerations:
                - Time Complexity: O(V + E), where V is number of vertices and E is number of edges.
                - Space Complexity: O(1), no extra storage used.

        6. getVertices() method
            Returns the set of the vertices in the graph.
            Used by Dijkstra’s algorithm to initialize distances and priority queue.
            Efficiency Considerations:
                - Time Complexity: O(1), returns a reference.
                - Space Complexity: O(V), size of the vertex set.

    PriorityQueue.cpp: 
        1. insert() method
            Inserts a new string representing the vertex with the given priority into the multimap that represents the queue.
            Uses std::multimap<int, std::string>::insert() to insert a (priority, value) pair. Multimap automatically maintains order based on priority. 

            Efficiency Considerations:
                - Time Complexity: O(log n), for insertion into std::multimap
                - Space Complexity: O(n), where n is the number of elements in the queue.

        2. contains() method
            Checks if the string representing the vertex is already in the priority queue.
            Traverses the entire multimap and compares each string to the target value. 

            Efficiency Considerations:
                - Time Complexity: O(n), where n is the number of elements in the multimap.
                - Space Complexity: O(1), only comparisons are made.

        3. updatePriority() method
            Updates the priority of the string representing the vertex by first removing the old pair.
            Traverses the multimap to locate the entry by its string value. Once found, erases the current entry and insert it with the updated priority.

            Efficiency Considerations:
                - Time Complexity: O(n), where n is the number of elements in the multimap.
                - Space Complexity: O(1), only comparisons are made.

        4. extractMin() method
            Returns the string representing the vertex with the lowest priority.
            Since std::multimap is ordered by keys (priorities), the first element always has the minimum priority. That element is returned and removed from the map.

            Efficiency Considerations:
                - Time Complexity: O(1), for access and remove in std::multimap.
                - Space Complexity: O(1), no additional storage needed.

        5. isEmpty() method
            Returns if the priority queue is empty.
            Uses the built-in .empty() method from std::multimap to determine whether any elements are currently stored in the queue.

            Efficiency Considerations:
                - Time Complexity: O(1), for call method in std::multimap.
                - Space Complexity: O(1), no additional storage needed.

        6. print() method
            Prints the contents of the priority queue in priority order and following the format specified.
            Used for debugging and visual inspection of the internal state of the queue.

            Efficiency Considerations:
                - Time Complexity: O(n), where n is the number of elements.
                - Space Complexity: O(1), no additional storage needed.

    main.cpp: 
        1. dijkstra() function
            Implements Dijkstra’s algorithm using the Digraph and PriorityQueue classes.
            Initializes all distances. Then repeatedly visits the vertex with the smallest known distance, updating neighbors if a shorter path is found. 
            Uses PriorityQueue to manage the order and prints detailed steps and updates of path discovery. 

            Efficiency Considerations:
                - Time Complexity: O(V^2) in worst-case, where V size of the vertex set.
                Due to linear search in updatePriority() and contains()
                - Space Complexity: O(V + E), where V is number of vertices and E is number of edges. 
                We need to storage vertices, distances, edges, and the queue.

Known Limitations:
    I believe my code fully meets the requirements of the assignment for an input that follows the specifications outlined in the project description.

Test Cases:
    1.  Input: providedgraph1.txt
            undirected
            vertex a
            vertex b
            vertex c
            vertex d
            vertex e
            edge a e 9
            edge a b 7
            edge b c 15
            edge b e 10
            edge c d 6
            edge c e 11
            dijkstra a d

        Output: 
            Vertices: a b c d e 
            Directed edges: 
            a -> e: 9
            a -> b: 7
            b -> a: 7
            b -> c: 15
            b -> e: 10
            c -> b: 15
            c -> d: 6
            c -> e: 11
            d -> c: 6
            e -> a: 9
            e -> b: 10
            e -> c: 11

            Run dijkstra a d 5
            Visiting vertex a
            End vertex: e
            Updating distances[e] from 1000000 to 9
            End vertex: b
            Updating distances[b] from 1000000 to 7
            Visiting vertex b
            End vertex: a
            End vertex: c
            Updating distances[c] from 1000000 to 22
            End vertex: e
            Visiting vertex e
            End vertex: a
            End vertex: b
            End vertex: c
            Updating distances[c] from 22 to 20
            Visiting vertex c
            End vertex: b
            End vertex: d
            Updating distances[d] from 1000000 to 26
            End vertex: e
            Visiting vertex d

            Shortest path is:
            a e c d 

            It has length: 26
            Final map of distances:
            a: 0
            b: 7
            c: 20
            d: 26
            e: 9

            Final map of previous vertices:
            a: 
            b: a
            c: e
            d: c
            e: a

        Why?: Ensures that the algorithm is capable of  updating distances when a better path is discovered after initial exploration. It also tests that the structure handles undirected edges as bidirectional correctly and that all paths are fully evaluated before determining the shortest one. 
    
    2.  Input: providedgraph2.txt
            undirected
            vertex amarillo
            vertex austin
            vertex dallas
            vertex houston
            vertex san_antonio
            edge amarillo austin 416
            edge amarillo dallas 334
            edge amarillo san_antonio 445
            edge austin dallas 182
            edge dallas houston 224
            edge houston san_antonio 189
            dijkstra amarillo houston

        Output: 
            Vertices: amarillo austin dallas houston san_antonio 
            Directed edges: 
            amarillo -> austin: 416
            amarillo -> dallas: 334
            amarillo -> san_antonio: 445
            austin -> amarillo: 416
            austin -> dallas: 182
            dallas -> amarillo: 334
            dallas -> austin: 182
            dallas -> houston: 224
            houston -> dallas: 224
            houston -> san_antonio: 189
            san_antonio -> amarillo: 445
            san_antonio -> houston: 189

            Run dijkstra amarillo houston 5
            Visiting vertex amarillo
            End vertex: austin
            Updating distances[austin] from 1000000 to 416
            End vertex: dallas
            Updating distances[dallas] from 1000000 to 334
            End vertex: san_antonio
            Updating distances[san_antonio] from 1000000 to 445
            Visiting vertex dallas
            End vertex: amarillo
            End vertex: austin
            End vertex: houston
            Updating distances[houston] from 1000000 to 558
            Visiting vertex austin
            End vertex: amarillo
            End vertex: dallas
            Visiting vertex san_antonio
            End vertex: amarillo
            End vertex: houston
            Visiting vertex houston

            Shortest path is:
            amarillo dallas houston 

            It has length: 558
            Final map of distances:
            amarillo: 0
            austin: 416
            dallas: 334
            houston: 558
            san_antonio: 445

            Final map of previous vertices:
            amarillo: 
            austin: amarillo
            dallas: amarillo
            houston: dallas
            san_antonio: amarillo

        Why?: Simulates a real-world map with large edge weights and multiple long paths. It also makes sure large weights don’t interfere with priority comparisons and that Dijkstra’s logic stays intact under such values.

    3.  Input: providedgraph3.txt
            directed
            vertex red
            vertex blue
            vertex green
            vertex yellow
            edge red blue 8
            edge red green 3
            edge blue yellow 6
            edge green yellow 2
            edge yellow blue 1
            dijkstra red yellow

        Output: 
            Vertices: a b c d e f s t 
            Directed edges: 
            a -> b: 5
            a -> c: 20
            a -> t: 44
            b -> c: 30
            b -> e: 18
            c -> d: 11
            c -> e: 2
            c -> t: 16
            d -> e: 6
            d -> t: 6
            e -> f: 24
            e -> t: 19
            s -> f: 9
            s -> b: 14
            s -> a: 15

            Run dijkstra s t 8
            Visiting vertex s
            End vertex: f
            Updating distances[f] from 1000000 to 9
            End vertex: b
            Updating distances[b] from 1000000 to 14
            End vertex: a
            Updating distances[a] from 1000000 to 15
            Visiting vertex f
            Visiting vertex b
            End vertex: c
            Updating distances[c] from 1000000 to 44
            End vertex: e
            Updating distances[e] from 1000000 to 32
            Visiting vertex a
            End vertex: b
            End vertex: c
            Updating distances[c] from 44 to 35
            End vertex: t
            Updating distances[t] from 1000000 to 59
            Visiting vertex e
            End vertex: f
            End vertex: t
            Updating distances[t] from 59 to 51
            Visiting vertex c
            End vertex: d
            Updating distances[d] from 1000000 to 46
            End vertex: e
            End vertex: t
            Visiting vertex d
            End vertex: e
            End vertex: t
            Visiting vertex t

            Shortest path is:
            s b e t 

            It has length: 51
            Final map of distances:
            a: 15
            b: 14
            c: 35
            d: 46
            e: 32
            f: 9
            s: 0
            t: 51

            Final map of previous vertices:
            a: s
            b: s
            c: a
            d: c
            e: b
            f: s
            s: 
            t: e

        Why?: Tests the algorithm with a densely connected and directed graph with multiple entry points to the destination. It ensures that shortest paths are correctly reevaluated when better options arise later in the process.

    4.  Input: providedgraph4.txt
            undirected
            vertex a
            vertex b
            vertex c
            vertex d
            vertex e
            vertex f
            edge a e 14
            edge a f 9
            edge a b 7
            edge b c 15
            edge b f 10
            edge c d 6
            edge c f 11
            edge d e 10
            edge f e 2
            dijkstra a d

        Output: 
            Vertices: a b c d e f 
            Directed edges: 
            a -> e: 14
            a -> f: 9
            a -> b: 7
            b -> a: 7
            b -> c: 15
            b -> f: 10
            c -> b: 15
            c -> d: 6
            c -> f: 11
            d -> c: 6
            d -> e: 10
            e -> a: 14
            e -> d: 10
            e -> f: 2
            f -> a: 9
            f -> b: 10
            f -> c: 11
            f -> e: 2

            Run dijkstra a d 6
            Visiting vertex a
            End vertex: e
            Updating distances[e] from 1000000 to 14
            End vertex: f
            Updating distances[f] from 1000000 to 9
            End vertex: b
            Updating distances[b] from 1000000 to 7
            Visiting vertex b
            End vertex: a
            End vertex: c
            Updating distances[c] from 1000000 to 22
            End vertex: f
            Visiting vertex f
            End vertex: a
            End vertex: b
            End vertex: c
            Updating distances[c] from 22 to 20
            End vertex: e
            Updating distances[e] from 14 to 11
            Visiting vertex e
            End vertex: a
            End vertex: d
            Updating distances[d] from 1000000 to 21
            End vertex: f
            Visiting vertex c
            End vertex: b
            End vertex: d
            End vertex: f
            Visiting vertex d

            Shortest path is:
            a f e d 

            It has length: 21
            Final map of distances:
            a: 0
            b: 7
            c: 20
            d: 21
            e: 11
            f: 9

            Final map of previous vertices:
            a: 
            b: a
            c: f
            d: e
            e: f
            f: a

        Why?: Tests with a dense graph with overlapping connections and many similar-cost paths, which allows to test priority queue accuracy and correct ordering of node visits. It confirms that the algorithm handles tie-breaking consistently and selects the truly optimal path when multiple near-optimal paths exist.

    5.  Input: testgraph1.txt
            directed
            vertex city1
            vertex city2
            vertex city3
            vertex city4
            vertex city5
            edge city1 city2 2
            edge city2 city3 3
            edge city3 city4 4
            edge city4 city5 5
            edge city1 city5 99
            dijkstra city1 city5

        Output: 
            Vertices: city1 city2 city3 city4 city5 
            Directed edges: 
            city1 -> city2: 2
            city1 -> city5: 99
            city2 -> city3: 3
            city3 -> city4: 4
            city4 -> city5: 5

            Run dijkstra city1 city5 5
            Visiting vertex city1
            End vertex: city2
            Updating distances[city2] from 1000000 to 2
            End vertex: city5
            Updating distances[city5] from 1000000 to 99
            Visiting vertex city2
            End vertex: city3
            Updating distances[city3] from 1000000 to 5
            Visiting vertex city3
            End vertex: city4
            Updating distances[city4] from 1000000 to 9
            Visiting vertex city4
            End vertex: city5
            Updating distances[city5] from 99 to 14
            Visiting vertex city5

            Shortest path is:
            city1 city2 city3 city4 city5 

            It has length: 14
            Final map of distances:
            city1: 0
            city2: 2
            city3: 5
            city4: 9
            city5: 14

            Final map of previous vertices:
            city1: 
            city2: city1
            city3: city2
            city4: city3
            city5: city4

        Why?: Ensures the algorithm avoids a tempting but misleading direct path with a high cost. It checks that the algorithm properly accumulates weights over a chain of cheaper edges instead of jumping to a far node too early. It makes sure the internal comparison logic is solid and consistent.

    6.  Input: testgraph2.txt
            undirected
            vertex tokyo
            vertex osaka
            vertex nagoya
            vertex kyoto
            edge tokyo osaka 20
            edge osaka nagoya 20
            edge nagoya kyoto 20
            edge kyoto tokyo 5
            dijkstra tokyo nagoya
        Output: 
            Vertices: kyoto nagoya osaka tokyo 
            Directed edges: 
            kyoto -> nagoya: 20
            kyoto -> tokyo: 5
            nagoya -> osaka: 20
            nagoya -> kyoto: 20
            osaka -> tokyo: 20
            osaka -> nagoya: 20
            tokyo -> osaka: 20
            tokyo -> kyoto: 5

            Run dijkstra tokyo nagoya 4
            Visiting vertex tokyo
            End vertex: osaka
            Updating distances[osaka] from 1000000 to 20
            End vertex: kyoto
            Updating distances[kyoto] from 1000000 to 5
            Visiting vertex kyoto
            End vertex: nagoya
            Updating distances[nagoya] from 1000000 to 25
            End vertex: tokyo
            Visiting vertex osaka
            End vertex: tokyo
            End vertex: nagoya
            Visiting vertex nagoya

            Shortest path is:
            tokyo kyoto nagoya 

            It has length: 25
            Final map of distances:
            kyoto: 5
            nagoya: 25
            osaka: 20
            tokyo: 0

            Final map of previous vertices:
            kyoto: tokyo
            nagoya: kyoto
            osaka: tokyo
            tokyo:

        Why?: Ensures that the algorithm correctly explores cycles and can find less obvious but shorter paths that go “around” instead of straight through. This test checks that backtracking through undirected edges works as expected and helps ensure priority updates are properly handled.

    7.  Input: testgraph3.txt
            directed
            vertex red
            vertex blue
            vertex green
            vertex yellow
            edge red blue 8
            edge red green 3
            edge blue yellow 6
            edge green yellow 2
            edge yellow blue 1
            dijkstra red yellow 

        Output: 
            Vertices: blue green red yellow 
            Directed edges: 
            blue -> yellow: 6
            green -> yellow: 2
            red -> blue: 8
            red -> green: 3
            yellow -> blue: 1

            Run dijkstra red yellow 4
            Visiting vertex red
            End vertex: blue
            Updating distances[blue] from 1000000 to 8
            End vertex: green
            Updating distances[green] from 1000000 to 3
            Visiting vertex green
            End vertex: yellow
            Updating distances[yellow] from 1000000 to 5
            Visiting vertex yellow
            Visiting vertex blue
            End vertex: yellow

            Shortest path is:
            red green yellow 

            It has length: 5
            Final map of distances:
            blue: 8
            green: 3
            red: 0
            yellow: 5

            Final map of previous vertices:
            blue: red
            green: red
            red: 
            yellow: green

        Why?: Tests the algorithm's handling of directed cycles, specifically whether it avoids infinite loops and ignores revisiting previously finalized nodes. It also pushes the algorithm to pick between two paths of different cost, checking the correctness of the priority queue’s behavior after a cycle is introduced.

    8.  Input: testgraph4.txt
            undirected
            vertex comet
            vertex meteor
            vertex asteroid
            vertex blackhole
            edge comet meteor 12
            edge meteor asteroid 12
            dijkstra comet asteroid
        Output: 
            Vertices: asteroid blackhole comet meteor 
            Directed edges: 
            asteroid -> meteor: 12
            comet -> meteor: 12
            meteor -> comet: 12
            meteor -> asteroid: 12

            Run dijkstra comet asteroid 4
            Visiting vertex comet
            End vertex: meteor
            Updating distances[meteor] from 1000000 to 12
            Visiting vertex meteor
            End vertex: comet
            End vertex: asteroid
            Updating distances[asteroid] from 1000000 to 24
            Visiting vertex asteroid
            Visiting vertex blackhole

            Shortest path is:
            comet meteor asteroid 

            It has length: 24
            Final map of distances:
            asteroid: 24
            blackhole: 1000000
            comet: 0
            meteor: 12

            Final map of previous vertices:
            asteroid: meteor
            blackhole: 
            comet: 
            meteor: comet

        Why?: Checks if the algorithm behaves collectly when there's an unreachable vertex in the graph. Ensures that non-connected nodes don’t cause crashes or affect the output. It confirms the edge case of non-participating nodes.

    9.  Input: testgraph5.txt
            directed
            vertex x
            vertex y
            vertex z
            vertex q
            vertex p
            edge x y 5
            edge x z 2
            edge z y 3
            edge y p 4
            edge z q 8
            edge q p 6
            dijkstra x p

        Output: 
            Vertices: p q x y z 
            Directed edges: 
            q -> p: 6
            x -> y: 5
            x -> z: 2
            y -> p: 4
            z -> y: 3
            z -> q: 8

            Run dijkstra x p 5
            Visiting vertex x
            End vertex: y
            Updating distances[y] from 1000000 to 5
            End vertex: z
            Updating distances[z] from 1000000 to 2
            Visiting vertex z
            End vertex: y
            End vertex: q
            Updating distances[q] from 1000000 to 10
            Visiting vertex y
            End vertex: p
            Updating distances[p] from 1000000 to 9
            Visiting vertex p
            Visiting vertex q
            End vertex: p

            Shortest path is:
            x y p 

            It has length: 9
            Final map of distances:
            p: 9
            q: 10
            x: 0
            y: 5
            z: 2

            Final map of previous vertices:
            p: y
            q: z
            x: 
            y: x
            z: x

        Why?: Tests case focuses on multiple possible paths to the goal. It ensures that even when alternative routes exist, the algorithm consistently chooses the optimal one by continuously updating priorities when shorter paths are found mid-execution. 

Collaboration, Resources, AI Usage:
    No collaboration
    No other resources were used
    No IA was used

Honor Code:
    “I have acted with honesty and integrity in producing this work and am unaware of anyone who has not.”