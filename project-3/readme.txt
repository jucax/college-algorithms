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
    1. insert() method
        HashSetSTL:
            Insert a value into the set, returning true if it is new to the current set.
            Uses .insert(), which places the value into an appropriate bucket and return a pair with a boolean value indicating if it was a succesfull insertion or not. No manual resizing is needed since unordered_set handles it automatically.

        HashSetChaining:
            Insert a value into the set, returning true if it is new to the current set.
            Manually checks if the value exists using contains(). If not found, inserts it at the end of the corresponding bucket's list. If the load factor exceeds MAX_LOAD_FACTOR, it doubles the table size and redistributes the values using resizeTable().

        Efficiency Considerations:
            - Time Complexity: 
                Both: Average O(1), Worst O(n) in case of hash collisions.
            - Space Complexity:  
                STL: O(n) due to internal structures.
                Chaining: O(n + m), where n is the number of elements, and m is the number of buckets.

    2. removes() method
        HashSetSTL:
            Remove a value from the set, returning true if the value was actually removed.
            Uses std::unordered_set.erase(). If value existed, it’s removed and returns true, otherwise false. No manual resizing is needed since unordered_set handles it automatically.

        HashSetChaining:
            Remove a value from the set, returning true if the value was actually removed.
            It computes the appropriate bucket using computeHash(), then traverses the list, if the value is found, it is erased and the load factor is checked.
            If load factor drops below MIN_LOAD_FACTOR, table size is halved and elements are rehashed.

        Efficiency Considerations:
            - Time Complexity: 
                STL: Average O(1), Worst O(n) due to potential bucket growth.
                Chaining: O(n), where n is the number of elements in the target bucket.
            - Space Complexity:  
                Both: O(1) additional space; in-place removal.

    3. contains() method
        HashSetSTL:
            Return the table location of value if the value is in the set and return -1 if the value is not in the set.
            Uses std::unordered_set.find() to check if the set contains the value, and if it does std::unordered_set.bucket() to return the location

        HashSetChaining:
            Return the table location of value if the value is in the set and return -1 if the value is not in the set.
            Uses computeHash(value)to access the correct bucket, then searches through the list to check if the value exists in that bucket.

        Efficiency Considerations:
            - Time Complexity: 
                STL: Average O(1), Worst O(n).
                Chaining: O(n) where n is the bucket size.
            - Space Complexity:  
                Both: O(1), no more space needed.

    4. printSet() method
        HashSetSTL:
            Print the elements of the set, separated by spaces.

        HashSetChaining:
            Print the elements of the set, separated by spaces.

        Efficiency Considerations:
            - Time Complexity: 
                Both: O(n), where n is the number of elements in the set.
            - Space Complexity:  
                Both: O(1), no more space needed.

    5. printTable() method
        HashSetSTL:
            Print an error message (using cout) that is informative to the user since std::unordered_set doesn't give us the details that we have for separate chaining so we shouldn't try to print out the details of the empty buckets.

        HashSetChaining:
            Print the hash table contents, separated by spaces between buckets, noting the following:
                - for an empty bucket, display a hyphen, and nothing more
                - chained elements in a single bucket should be separated with ->

        Efficiency Considerations:
            - Time Complexity: 
                STL: O(1) just print message.
                Chaining: O(n + m), where n is the number of elements, and m is the number of buckets.
            - Space Complexity:  
                Both: O(1), no more space needed.

    6. getSize() method
        HashSetSTL:
            Return the number of elements currently stored in the std::unordered_set hashSet.

        HashSetChaining:
            Return the number of values in the set.
            Traverses each bucket (list) in the hash table,summing the size of each list

        Efficiency Considerations:
            - Time Complexity: 
                STL: O(1) just return the result.
                Chaining: O(m), where m is number of buckets.
            - Space Complexity:  
                Both: O(1), no more space needed.

    7. getTableSize() method
        HashSetSTL:
            Return the size of the underlying hash table
            It is the current number of buckets used by the underlying std::unordered_set.

        HashSetChaining:
            Return the size of the underlying hash table
            Which in thie implementation is the size of the hashTable vector.

        Efficiency Considerations:
            - Time Complexity: 
                Both: O(1) just return the result.
            - Space Complexity:  
                Both: O(1), no more space needed.

    8. getLoadFactor() method
        HashSetSTL:
            Return the load factor associated with this table
            Retrieved directly using the built-in unordered_set::load_factor() method

        HashSetChaining:
            Return the load factor associated with this table 
            Using the getSize() and getTableSize() methods we can calculate it as stored elements divided by the number of buckets. 
            Need to casts to double to ensure floating-point division.

        Efficiency Considerations:
            - Time Complexity: 
                STL: O(1) just return the result.
                Chaining: O(m), where m is number of buckets.
            - Space Complexity:  
                Both: O(1), no more space needed.

    9. resizeTable() method
        HashSetChaining:
            Rehashes all elements into a new table of size newSize.
            Each value is reinserted into the new table using value % newSize as the new hash formula 
            To ensure each value is placed in a valid bucket for the resized table.

        Efficiency Considerations:
            - Time Complexity: 
                Chaining: O(n), where n is number of elements, rehash and insert all elements.
            - Space Complexity:  
                Chaining: O(n + m), for the new table of size m and n elements.

Known Limitations:
    I believe my code fully meets the requirements of the assignment for an input that follows the specifications outlined in the project description.

Test Cases:
    1.  Input: test1.txt
        r 42
        r 99
        r 7
        i 42
        i 99
        i 7
        r 42
        r 99
        r 7
        r 7
        Output: 
        ---=== Hashing test1.txt with STL Unordered Set ===---
            Number of Elements: 0
                    Table Size: 5
                    Load Factor: 0
                Set elements: 
            Table elements: Error: Detailed table structure is not available in std::unordered_set. Bucket-level access is not supported in this implementation

            Checking contains() for values from 1 to 100:
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 

            ---=== Hashing test1.txt with Chaining ===---
            Number of Elements: 0
                    Table Size: 2
                    Load Factor: 0
                Set elements: 
            Table elements: - - 

            Checking contains() for values from 1 to 100:
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 

            Hash sets are consistent for the considered values  
        Why?: Ensures that removing values not present in the set is handled gracefully and does not affect the structure, followed by successful insertions and valid removals. Also tests that removing an already-removed element does not cause errors.
    2.  Input: test2.txt
        i 18
        i 18
        i 18
        i 29
        i 29
        i 29
        i 42
        i 42
        Output: 
        ---=== Hashing test2.txt with STL Unordered Set ===---
            Number of Elements: 3
                    Table Size: 5
                    Load Factor: 0.6
                Set elements: 42 29 18 
            Table elements: Error: Detailed table structure is not available in std::unordered_set. Bucket-level access is not supported in this implementation

            Checking contains() for values from 1 to 100:
                F F F F F F F F F F 
                F F F F F F F T F F 
                F F F F F F F F T F 
                F F F F F F F F F F 
                F T F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 

            ---=== Hashing test2.txt with Chaining ===---
            Number of Elements: 3
                    Table Size: 8
                    Load Factor: 0.375
                Set elements: 18 42 29 
            Table elements: - - 18->42 - - 29 - - 

            Checking contains() for values from 1 to 100:
                F F F F F F F F F F 
                F F F F F F F T F F 
                F F F F F F F F T F 
                F F F F F F F F F F 
                F T F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 

            Hash sets are consistent for the considered values 
        Why?: Verifies that inserting a duplicate value multiple times does not increase the size of the set and confirms that only the first insertion is considered valid while the rest are ignored.
    3.  Input: test3.txt
        i 1
        i 2
        i 3
        i 4
        i 5
        i 6
        i 7
        i 8
        i 9
        i 10
        i 11
        i 12
        i 13
        i 14
        i 15
        i 16
        i 17
        i 18
        i 19
        i 20
        Output: 
        ---=== Hashing test3.txt with STL Unordered Set ===---
            Number of Elements: 20
                    Table Size: 23
                    Load Factor: 0.87

            Checking contains() for values from 1 to 100:
                T T T T T T T T T T 
                T T T T T T T T T T 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 

            ---=== Hashing test3.txt with Chaining ===---
            Number of Elements: 20
                    Table Size: 32
                    Load Factor: 0.625

            Checking contains() for values from 1 to 100:
                T T T T T T T T T T 
                T T T T T T T T T T 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 

            Hash sets are consistent for the considered values
        Why?: Confirms that inserting enough elements to exceed the maximum load factor properly triggers a rehash and increases the table size, while maintaining all existing values in the correct locations.
    4.  Input: test4.txt
        i 0
        i 1000
        i 2147483647
        r 0
        r 1000
        r 2147483647
        i 2147483647
        i 0
        Output: 
        ---=== Hashing test4.txt with STL Unordered Set ===---
            Number of Elements: 2
                    Table Size: 5
                    Load Factor: 0.4
                Set elements: 0 2147483647 
            Table elements: Error: Detailed table structure is not available in std::unordered_set. Bucket-level access is not supported in this implementation

            Checking contains() for values from 1 to 100:
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 

            ---=== Hashing test4.txt with Chaining ===---
            Number of Elements: 2
                    Table Size: 2
                    Load Factor: 1
                Set elements: 0 2147483647 
            Table elements: 0 2147483647 

            Checking contains() for values from 1 to 100:
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 

            Hash sets are consistent for the considered values
        Why?: Validates the correct behavior of the set when handling boundary and edge values including zero and large integers, ensuring the hash function and table handle these without overflow or misplacement.
    5.  Input: test5.txt
        i 10
        i 15
        i 20
        i 25
        i 30
        r 15
        r 30
        r 100
        i 15
        i 100
        r 10
        i 10
        r 25
        i 200
        i 300
        i 400
        r 200
        Output: 
        ---=== Hashing test5.txt with STL Unordered Set ===---
            Number of Elements: 6
                    Table Size: 11
                    Load Factor: 0.545
                Set elements: 300 10 100 400 15 20 
            Table elements: Error: Detailed table structure is not available in std::unordered_set. Bucket-level access is not supported in this implementation

            Checking contains() for values from 1 to 100:
                F F F F F F F F F T 
                F F F F T F F F F T 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F T 

            ---=== Hashing test5.txt with Chaining ===---
            Number of Elements: 6
                    Table Size: 16
                    Load Factor: 0.375
                Set elements: 400 20 100 10 300 15 
            Table elements: 400 - - - 20->100 - - - - - 10 - 300 - - 15 

            Checking contains() for values from 1 to 100:
                F F F F F F F F F T 
                F F F F T F F F F T 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F F 
                F F F F F F F F F T 

            Hash sets are consistent for the considered values
        Why?: Simulates a realistic sequence of operations with a mix of inserts and removes including reinsertions and removals of non-existing elements, ensuring consistent set behavior throughout and accurate state tracking.
    6.  Input: test5.txt
        r 13
        i 24
        r 58
        i 36
        r 19
        i 48
        r 67
        i 91
        r 82
        i 17
        r 33
        i 40
        r 61
        i 53
        r 74
        i 65
        r 89
        i 22
        r 27
        i 38
        r 41
        i 59
        r 72
        i 80
        r 95
        i 11
        r 16
        i 32
        r 49
        i 44
        r 63
        i 66
        r 77
        i 93
        r 84
        i 26
        r 36
        i 55
        r 69
        i 79
        r 91
        i 15
        r 22
        i 47
        r 53
        i 61
        r 86
        i 99
        r 9
        i 19
        r 34
        i 50
        r 56
        i 68
        r 74
        i 85
        r 12
        i 28
        r 31
        i 42
        r 64
        i 70
        r 81
        i 88
        r 6
        i 14
        r 25
        i 35
        r 47
        i 60
        r 73
        i 95
        r 18
        Output: 
        ---=== Hashing test6.txt with STL Unordered Set ===---
            Number of Elements: 31
                    Table Size: 47
                    Load Factor: 0.66

            Checking contains() for values from 1 to 100:
                F F F F F F F F F F 
                T F F T T F T F T F 
                F F F T F T F T F F 
                F T F F T F F T F T 
                F T F T F F F T F T 
                F F F F T F F F T T 
                T F F F T T F T F T 
                F F F F F F F F T T 
                F F F F T F F T F F 
                F F T F T F F F T F 

            ---=== Hashing test6.txt with Chaining ===---
            Number of Elements: 31
                    Table Size: 64
                    Load Factor: 0.484

            Checking contains() for values from 1 to 100:
                F F F F F F F F F F 
                T F F T T F T F T F 
                F F F T F T F T F F 
                F T F F T F F T F T 
                F T F T F F F T F T 
                F F F F T F F F T T 
                T F F F T T F T F T 
                F F F F F F F F T T 
                F F F F T F F T F F 
                F F T F T F F F T F 

            Hash sets are consistent for the considered values
        Why?: Mimics a long realistic usage scenario with alternating inserts and removes, testing the hash set’s consistency over time. It covers a variety of operations.

    Collaboration, Resources, AI Usage:
        No collaboration
        No other resources were used
        No IA was used

    Honor Code:
        “I have acted with honesty and integrity in producing this work and am unaware of anyone who has not.”