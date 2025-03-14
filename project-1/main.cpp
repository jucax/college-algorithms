#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

/**
 * Reads characters from user input and counts occurrences of symbold in the ASCII range '!'(33) to '@'(64).
 * 
 * The function uses an array to store counts of each character in the specified range.
 * It continues reading characters until an input falls outside the range.
 * If an input character is outsite the range, an error message is displayed and the reading stops.
 * At the end, it prints each character from '!' to '@' along with its respective count.
 */
void function1(){
    std::cout << "--- Begin Function 1 ---" << std::endl;
    
    char symbol;
    bool reading = true;
    const int arraySize = '@' - '!' + 1; // Size of the array based on ASCII values in the range
    int symbolsCount[arraySize] = {0}; // Array to keep track of the counts of each symbol

    while (reading) {
        std::cin >> symbol;

        // Check if the input is within the valid ASCII range
        if (symbol < '!' || symbol > '@') {
            std::cout << "Not an ASCII character in the desired range" << std::endl;
            reading = false;
        } 

        int index = symbol - '!'; // Convert ASCII character to array index
        symbolsCount[index]++; // Increment count for that character
    }

    // Print the values
    for (int i = 0; i < arraySize; i++) {
        char symbol = '!' + i; // Convert index back to ASCII character
        std::cout << symbol << ": " << symbolsCount[i] << std::endl;
    }

    std::cout << "---   End Function 1 ---" << std::endl;
}

/**
 * Takes an string 'word' and generates a new string consisting of 'count' copies of portions of 'word', 
 * separated by characters from other 'separators' string.
 * 
 * For each copy of 'word', the last character of the string is removed until either 'count' portions 
 * are added or there are no characters left in the 'word'. 
 * Each copy is separated by successive characters from 'separators', repeating from the beginning if needed.
 * 
 * @param word The original string to be copied and shortened.
 * @param separators The string containing characters used as separators between copies.
 * @param count The number of copies to include in the last string.
 */
void decreasingSeparatedCopies(std::string word, std::string separators, int count) {
    for (int i = 0 ; i < count && i < word.length() ; i++) {

        // Print word and remove one character from the end 
        for (int j = 0 ; j < word.length() - i ; j++) {
            std::cout << word[j];
        }

        // Print separator character and moves on to the next one
        if (!separators.empty() && i < count - 1 && word.length() - i > 1) {
            std::cout << separators[i % separators.length()]; //Cicle within separator string if necessary
        }
    }

    std::cout << std::endl;
}

/**
 * Runs tests for the `decreasingSeparatedCopies` function by calling it with specific inputs 
 * and printing the results.
 */
void function2(){
    std::cout << "--- Begin Function 2 ---" << std::endl;

    // Example tests
    decreasingSeparatedCopies("Southwestern", "1840", 6);
    decreasingSeparatedCopies("Southwestern", "", 3);
    decreasingSeparatedCopies("SU", "Texas", 4);

    // Edge cases tests
    decreasingSeparatedCopies("CS", "123", 4); // Count bigger than word length
    decreasingSeparatedCopies("X", "AB", 3); // One character word
    decreasingSeparatedCopies("Test", "x", 4); // One character separator
    decreasingSeparatedCopies("Texas", "", 3); // No separators

    // Special characters tests
    decreasingSeparatedCopies("Hello World", "/& |", 8); // Spaces in word
    decreasingSeparatedCopies("@#$%^", "!?", 5); // Other symbols

    std::cout << "---   End Function 2 ---" << std::endl;
}

/**
 * Reads numbers from a text file and calculate:
 * 1. The maximum value in the file.
 * 2. The sum of the base-2 log of the ceiling for all positive numbers in the file.
 * If there aren't positive numbers in the file, it prints -1 for the sum.
 * If the file does not exist or cannot be opened, it throws and error and exits.
 * 
 * @throws std::error if the file does not exist or cannot be opened.
 */
void function3(){
    std::cout << "--- Begin Function 3 ---" << std::endl;
    // Declare and open input stream from numbers.txt
    std::ifstream fin;
    fin.open("numbers6.txt");

    // Throw error and exit if numbers.txt is not found
    if (fin.fail()) {
        std::cerr << "The file \"numbers.txt\" does not exist. Exiting."
                  << std::endl;
        exit(1);
    }

    double num;
    fin >> num; // Read first number

    double max = num; // Start assuming the first number is the maximum
    double log2_result = 0;
    bool positive = false; // Boolean flag to check if there is a positive number

    do {  
        // Update max if the current number is greater
        if (num > max) {
            max = num;
        }

        // Check if the number is positive to add it to the base-2 log sum
        if (num > 0) {
            positive = true;
            double log_value = std::log2(std::ceil(num)); // Compute base-2 log of the ceiling
            log2_result += log_value;
        }
    } while (fin >> num); 

    fin.close();

    // Print the maximum value
    std::cout << "Maximum value: " << max << std::endl;

    // Print the sum of base-2 log of the ceiling for positive numbers
    std::cout << "Sum of log2(ceil(num)) for positive numbers: " << (positive ? log2_result : -1) << std::endl; // If positive is still false, then print -1

    std::cout << "---   End Function 3 ---" << std::endl;
}

// Class that simulates the functionality of a 4-digit PIN system like that of a telephone.
class Passcode{
public:
   /**
      Simulates pushing a button corresponding to a digit
      @param button a digit 0 ... 9
   */
   void push(int button);
   /**
      Determines if the passcode is valid
      @return true if the entered passcode matches the secret value
   */
   bool valid();
    /**
      Removes the last entered digit from the passcode.
      If no digits have been entered, nothing is done.
    */
   void operator--();

private:
    // digits start empty
    int digit1 = -1;
    int digit2 = -1;
    int digit3 = -1;
    int digit4 = -1;
    int numberOfDigit = 0;

    // Secret code
    static const int SECRET_DIGIT1 = 0;
    static const int SECRET_DIGIT2 = 1;
    static const int SECRET_DIGIT3 = 2;
    static const int SECRET_DIGIT4 = 3;
};

void Passcode::push(int button) {
    // Assign digits to their corresponding place 
    if (numberOfDigit < 4) {
        switch (numberOfDigit) {
        case 0:
            digit1 = button;
        break;
        case 1:
            digit2 = button;
        break;
        case 2:
            digit3 = button;
        break;
        case 3:
            digit4 = button;
        break;
        default:
            break;
        }
        numberOfDigit++; // Move one position after read
    } else numberOfDigit--; // Move back one position, which means digit removed
}

bool Passcode::valid() {
    // Check if the digits match with the password
    bool isValid = (digit1 == SECRET_DIGIT1 && digit2 == SECRET_DIGIT2 &&
            digit3 == SECRET_DIGIT3 && digit4 == SECRET_DIGIT4);

    // Reset the passcode after validity check
    digit1 = -1;
    digit2 = -1;
    digit3 = -1;
    digit4 = -1;
    numberOfDigit = 0;

    return isValid;
}

void Passcode::operator--() {
    // Check if at least one digit have been introduced
    if (numberOfDigit > 0) {
        // Remove the most recent digit
        numberOfDigit --;
        switch (numberOfDigit) {
        case 0:
            digit1 = -1;
        break;
        case 1:
            digit2 = -1;
        break;
        case 2:
            digit3 = -1;
        break;
        case 3:
            digit4 = -1;
        break;

        default:
            break;
        }
    }
}

/**
 * Runs multiple input sequences to tests the functionality of the Passcode class.
 * Compares the actual outcomes with the expected results to ensure the passcode validation
 * works correctly. Both expected and actual results are printed.
*/
void function4(){
    std::cout << "--- Begin Function 4 ---" << std::endl;
    // The valid secret code for this iPhone is 0123. 

    Passcode iPhone;
    iPhone.push(2);
    iPhone.push(3);
    std::cout << std::boolalpha << iPhone.valid() << std::endl;
    std::cout << "Expected: false" << std::endl;
    iPhone.push(0);
    iPhone.push(1);
    iPhone.push(2);
    iPhone.push(3);
    std::cout << iPhone.valid() << std::endl;
    std::cout << "Expected: true" << std::endl;
    iPhone.push(1);
    iPhone.push(2);
    iPhone.push(3);
    std::cout << iPhone.valid() << std::endl;
    std::cout << "Expected: false" << std::endl;
    iPhone.push(0);
    iPhone.push(0);
    iPhone.push(1);
    iPhone.push(2);
    iPhone.push(3);
    std::cout << iPhone.valid() << std::endl;
    std::cout << "Expected: false" << std::endl;
    iPhone.push(0);
    iPhone.push(1);
    iPhone.push(2);
    iPhone.push(3);
    std::cout << iPhone.valid() << std::endl;
    std::cout << "Expected: true" << std::endl;

    // Other tests
    std::cout << "Other tests" << std::endl;
    Passcode Nokia;
    Nokia.push(0);
    Nokia.push(1);
    Nokia.push(2);
    Nokia.push(3);
    --Nokia;  // Removes the last digit (3)
    std::cout << Nokia.valid() << std::endl;
    std::cout << "Expected: false" << std::endl;

    Passcode Samsung;
    Samsung.push(0);
    Samsung.push(1);
    Samsung.push(2);
    Samsung.push(4);
    --Samsung;  // Removes the last digit (4)
    Samsung.push(3);  // Enters the last digit of the secret code
    std::cout << Samsung.valid() << std::endl;
    std::cout << "Expected: true" << std::endl;

    Passcode Motorola;
    Motorola.push(9);
    Motorola.push(8);
    Motorola.push(7);
    Motorola.push(6);
    --Motorola; // Remove all the last digits
    --Motorola;
    --Motorola;
    --Motorola;
    Motorola.push(0);  // Enters the correct code in the empty space
    Motorola.push(1);
    Motorola.push(2);
    Motorola.push(3);
    std::cout << Motorola.valid() << std::endl;
    std::cout << "Expected: true" << std::endl;

    Passcode Sony;
    Sony.push(0);
    Sony.push(0);
    Sony.push(0);
    Sony.push(0);
    std::cout << Sony.valid() << std::endl;
    std::cout << "Expected: false" << std::endl;

    Passcode Huawei;
    --Huawei; // Test when there is nothing to remove
    Huawei.push(8);
    --Huawei; // Test for remove one number
    Huawei.push(0);
    Huawei.push(1);
    Huawei.push(2); 
    Huawei.push(3);
    std::cout << Huawei.valid() << std::endl;
    std::cout << "Expected: true" << std::endl;

    Passcode Blackberry;
    std::cout << Blackberry.valid() << std::endl; // Test for empty code
    std::cout << "Expected: false" << std::endl;

    std::cout << "---   End Function 4 ---" << std::endl;
}

/**
 * Acts as the program starting point, allowing the user to select and run one of four preovious functions.
 * Depending on the number the user introduces from 1 to 4, the associated function is executed.
 * If the input is outside the valid range, no action is taken and the execution stops.
*/
int main() {
    int functionNumber;
    std::cin >> functionNumber;
    switch (functionNumber) {
        case 1:
            function1();
            break;
        case 2:
            function2();
            break;
        case 3:
            function3();
            break;
        case 4:
            function4();
            break;
    }

    return 0;
}