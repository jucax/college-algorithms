ALGORITHMS PROJECT 1 README
Student:
    Juan Martinez

Files submitted:
    - main.cpp - Main program file containing the implementations of the four functions that make up this project.
    - numbers.txt - A text file containing both positive and negative numbers to test function3.
    - numbers1.txt - A text file containing all positive numbers to test function3.
    - numbers2.txt - A text file containing all negative numbers to test function3.
    - numbers3.txt - A text file containing large decimal numbers to test function3.
    - numbers4.txt - A text file containing both large positive and negative numbers to test function3.
    - numbers5.txt - A test file containing just one number.
    - numbers6.txt – A test file containing no numbers.

High-Level Overview:
    1. function1
        This function1 reads characters from the input and counts how often each symbol appears within a specific ASCII range, from '!' (33) to '@' (64). It uses a fixed-size array to store the appearances of each character in this range. The function stops reading  as soon as it encounters a character outside this range, then it prints all the symbols in the range, along with the count of each symbol.

        To link each character to the correct position in the array, the function uses ASCII decimal positions. It subtracts the ASCII value of '!' from the ASCII value of the character, which gives the exact index for that character in the array. This avoids the need for more complex structures. The 'symbolsCount' array starts with all values set to zero and gets updated as the function reads and processes each character from the input.

        Efficiency Considerations:
            - Time Complexity: The function1 processes n input characters in O(n) time, as each character is read, checked, and mapped to an array index. The final step, which prints the counts of the symbols, runs in O(1) time since the array size is fixed at 32 spaces (range from 33 to 64). The dominant operation is n, so in general this function runs in O(n) time. 
                Best & Worst case: O(n)
            - Space Complexity: The function1 requires constant space O(1) as it uses a fixed-size array of 32 integers. There’s no need for dynamic memory allocation or extra data structures.

    2. decreasingSeparatedCopies function & function2
        The 'decreasingSeparatedCopies' function creates a string by gradually shortening the input 'word' and inserting characters from the 'separators' string between each shortened copy. This process repeats until either the specified number of copies 'count' is reached or the 'word' has no more characters remaining. If the separators string doesn’t have enough characters, it loops back to the first character.

        The function 'decreasingSeparatedCopies' works by iterating up to the smaller of 'count' or the length of the 'word'. During each iteration, it prints a shorter version of the 'word' and cycles through the 'separators' characters as needed. 

        The test cases in function2 ensure that the 'decreasingSeparatedCopies' function works correctly with different inputs, confirming a correct string creation.

        Efficiency Considerations:
            - Time Complexity: The function  'decreasingSeparatedCopies' runs in O(n^2) time in the worst case, where n is the length of word. This is because for each copy, a substring of decreasing length is printed (O(n) + O(n-1) + O(n-2) + ... + O(1) = O(n^2)). 
                Best & Worst case: O(n^2)
            - Space Complexity: The function 'decreasingSeparatedCopies' only uses constant O(1) extra space, as it directly prints characters without storing the final string in memory.

    3. function3
        The function3 reads through a file of numerical values, processing each number only once to calculate two main results:
            1. Maximum Value: Keeps track of the highest number found in the file and prints it.
            2. Logarithmic Sum: For every positive number, it calculates the base-2 logarithm of its ceiling value and adds it to a total sum. If there are no positive numbers, it returns -1.

        This implimentation process the file without unnecessary storage or re-reading. It ensures correctness across edge cases and the use of conditional checks and mathematical functions like ceil and log2 ensures accurate calculations.

        Efficiency Considerations:
            - Time Complexity: The function3 runs in O(n) time, where n is the number of lines in the file. Each number is read, checked for being the maximum, and processed for the logarithmic sum in constant O(1) time. Since this occurs for each of the n numbers only once, the overall complexity remains O(n).
                Best & Worst case: O(n)
            - Space Complexity: The function3 requires constant space O(1), as it maintains only three variables. No additional storage is used for the input values.

    4. Passcode class & function4
        The Passcode class represents a basic 4-digit PIN system that compares user input against a predefined secret code. It uses four integer variables (digit1 to digit4) to store the digits entered and includes a function to remove the last entered digit using the prefix -- operator. 
        
        It contains a valid() function that checks if the digits match the secret code and resets the digits after each check. 

        The test cases in function4 ensure that the class works correctly with different input sequences, confirming both validation and backspace functionality.

        Efficiency Considerations:
            - Time Complexity: Each operation push, valid, and operator-- runs in O(1) time, since they perform a fixed number of assignments and comparisons. 
                Best & Worst case: O(1)
            - Space Complexity: The function operates in O(1) extra space, as it store only four integer variables. It does not rely on arrays, vectors, or any other data structure.

Known Limitations:
    I believe my code fully meets the requirements of the assignment for all the implemented functions.

Test Cases:
    1. function1
        1.  Input: ""#$$$$$
            Output: 
            !: 0
            ": 2
            #: 1
            $: 5
            ...  (all 0)
            @: 0 
            Why?: Ensures correct counting of symbols.
        2.  Input: !!!@@@@###
            Output: 
            !: 3
            ": 0
            #: 3
            ...  (all 0)
            @: 4 
            Why?: Ensures correct counting for multiple occurrences.
        3.  Input: !@!@
            Output: 
            !: 2
            ...  (all 0)
            @: 2 
            Why?: Ensures first and last valid symbols work correctly.  
        4.  Input: #
            Output: 
            !: 0
            ": 0
            #: 1
            ...  (all 0)
            @: 0 
            Why?: Ensures that a minimum valid input works.
        5.  Input: (Empty input)
            Output: Not an ASCII character in the desired range
            Why?: Ensures the program handles empty input correctly.
        6.  Input: A
            Output: Not an ASCII character in the desired range
            Why?: Ensures function correctly terminates on inputs out of the range.

    2. decreasingSeparatedCopies function & function2
        1. Input: decreasingSeparatedCopies("CS", "123", 4);
           Output: CS1C
           Why?: Ensures correct handling when the count is greater than the word length.
        2. Input: decreasingSeparatedCopies("X", "AB", 3);
           Output: X
           Why?: Ensures correct handling with a one-character word.
        3. Input: decreasingSeparatedCopies("Test", "x", 4);
           Output: TestxTesxTexT
           Why?: Ensures correct handling with a single-character separator.
        4. Input: decreasingSeparatedCopies("Texas", "", 3);
           Output: TexasTexaTex
           Why?: Ensures correct handling when no separator is provided.
        5. Input: decreasingSeparatedCopies("Hello World", "/& |", 8);
           Output: Hello World/Hello Worl&Hello Wor Hello Wo|Hello W/Hello &Hello Hell
           Why?: Ensures correct handling spaces in both word and separator.
        6. Input: decreasingSeparatedCopies("@#$%^", "!?", 5);
           Output: @#$%^!@#$%?@#$!@#?@
           Why?: Ensures correct handling of special symbols in both word and separator.

    3. function3
        1. numbers.txt 
        Input: 3.5
               2.4
               5
               -9.0
               0.0000001
        Output: 
        Maximum value: 5
        Sum of log2(ceil(num)) for positive numbers: 5.90689
        Why?: Ensures correct handling of negative numbers and small positive values like 0.0000001
        2. numbers1.txt 
        Input: 10
               2
               0.8
               6
               0
        Output: 
        Maximum value: 10
        Sum of log2(ceil(num)) for positive numbers: 6.90689
        Why?: Ensures handling zero correctly.
        3. numbers2.txt 
        Input: -5
               -10.5
               -3
               -0.2
        Output: 
        Maximum value: -0.2
        Sum of log2(ceil(num)) for positive numbers: -1
        Why?: Ensuring handling negative values correctly, confirm they do not contribute to the logarithm sum
        4. numbers3.txt 
        Input: 0.0000006
               0.000001
               0.0004
               0.006
        Output: 
        Maximum value: 0.006
        Sum of log2(ceil(num)) for positive numbers: 0
        Why?: Ensuring handling tiny positive floating-point values without precision issue.
        5. numbers4.txt 
        Input: 1e-5
               -1e+4
               0.0000005
               1e+6
        Output: 
        Maximum value: 1e+06
        Sum of log2(ceil(num)) for positive numbers: 19.9316
        Why?: Ensuring handling scientific notation inputs.
        6. numbers5.txt 
        Input: 32
        Output: 
        Maximum value: 32
        Sum of log2(ceil(num)) for positive numbers: 5
        Why?: Ensuring handling a single positive number.
        5. numbers6.txt 
        Input: (empty input)
        Output: The file "numbers6.txt" does not exist. Exiting.
        Why?: Ensuring handling a nonexistent file.

    4. Passcode class & function4
        1. Nokia
        Input:  0
                1
                2
                3
                -1 (removes 3)
        Output: false
        Why?: Ensures that when a digit is removed, the passcode validity is checked correctly after the modification.
        2. Samsung
        Input:  0
                1
                2
                4
                -1 (removes 4)
                3 (enters correct 3)
        Output: true
        Why?: Ensures that removing an incorrect last digit and entering the correct one results in a valid passcode.
        3. Motorola
        Input:  9
                8
                7
                6
                (removes 6)
                (removes 7)
                (removes 8)
                (removes 0)
                0
                1
                2
                3
        Output: false
        Why?: Ensures that multiple remove operations correctly remove all the digits, allowing the user to enter a valid passcode afterward.
        4. Sony
        Input:  0
                0
                0
                0
        Output: false
        Why?: Ensures that an incorrect passcode with repeated zeros returns false.
        5. Huawei
        Input:  (removes nothing when empty)
                8
                (removes 8)
                0
                1
                2
                3
        Output: true
        Why?: Ensures that removing a digit when the passcode is empty or removing a single digit does not cause errors.
        6. Blackberry
        Input:  (no digits entered)
        Output: false
        Why?: Ensures that checking if valid without entering any digits returns false.

    Collaboration, Resources, AI Usage:
        No collaboration
        No other resources were used
        No IA was used

    Honor Code:
        “I have acted with honesty and integrity in producing this work and am unaware of anyone who has not.”