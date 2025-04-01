ALGORITHMS PROJECT 3 README
Student:
    Juan Martinez

Files submitted:
    - main.cpp – Main program that runs tests on both hash set implementations (HashSetChaining and HashSetSTL) using a test file and checks for discrepancies. It also reports metrics like load factor, table size, and set contents​.
    - HashSet.h – Interface header file defining the HashSet abstract class, including required public functions for any hash set implementation.
    - HashSetChaining.h – Header file for the chaining-based hash set class. It defines the internal structure using a vector of linked lists. Comments were added for clarity, but the logic remains untouched​.
    - HashSetSTL.h – Header file for the STL-based hash set class using std::unordered_set. Comments were added for clarity, but the logic remains untouched​.
    - HashSetChaining.cpp – Implements all methods from the HashSetChaining class using separate chaining. Includes table resizing, load factor calculations, hash computation, and insert/remove logic​.
    - HashSetSTL.cpp – Implements all methods from the HashSetSTL class by wrapping around std::unordered_set. Use built-in methods to implement table resizing, load factor calculations, hash computation, and insert/remove logic​.
    - data.txt – Provided test file used by main.cpp, consisting of commands to insert (i) and remove (r) integers from the hash sets using the format specified

High-Level Overview:
    1. insert(int value) method
        HashSetSTL:
            Uses std::unordered_set.insert() to add a value to the hash set. If the value already exists, it returns false; otherwise, true. No manual resizing is needed since unordered_set handles it automatically.

        HashSetChaining:
            Manually checks if the value exists using contains(). If not found, inserts it at the end of the corresponding bucket's list. If the load factor exceeds MAX_LOAD_FACTOR, it doubles the table size and redistributes the values using resizeTable().

        Efficiency Considerations:
            - Time Complexity: 
                STL: Average O(1), Worst O(n) in case of hash collisions.
                Chaining: O(1 + α) average, where α is the load factor (expected constant time for short chains).
            - Space Complexity:  
                
