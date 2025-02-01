#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

/* Be sure to provide the expected comments with each function */
void function1(){
    std::cout << "--- Begin Function 1 ---" << std::endl;
    
    char symbol;
    bool reading = true;
    int symbolsCount[32] = {0};
    while (reading) {
        std::cin >> symbol;
        if (symbol < '!' || symbol > '@') {
            std::cout << "Not an ASCII character in the desired range" << std::endl;
            reading = false;
        } 
        int index = symbol - '!';
        symbolsCount[index]++;
    }

    // Print the values
    for (int i = 0; i < 32; i++) {
        char symbol = '!' + i; 
        std::cout << symbol << ": " << symbolsCount[i] << std::endl;
    }

    std::cout << "---   End Function 1 ---" << std::endl;
}

void decreasingSeparatedCopies(std::string word, std::string separators, int count) {
    for (int i = 0 ; i < count && i < word.length() ; i++) {

        // Reduce last character in word
        for (int j = 0 ; j < word.length() - i ; j++) {
            std::cout << word[j];
        }

        // Print separator
        if (!separators.empty() && i < count - 1 && word.length() - i > 1) {
            std::cout << separators[i % separators.length()]; //Cicle within separator string
        }
    }
    std::cout << std::endl;
}

void function2(){
    std::cout << "--- Begin Function 2 ---" << std::endl;
    decreasingSeparatedCopies("Southwestern", "1840", 6);
    decreasingSeparatedCopies("Southwestern", "", 3);
    decreasingSeparatedCopies("SU", "Texas", 4);
    std::cout << "---   End Function 2 ---" << std::endl;
}

void function3(){
    std::cout << "--- Begin Function 3 ---" << std::endl;
    // declare and open input stream from numbers.txt
    std::ifstream fin;
    fin.open("Root/numbers.txt");
    // throw error and exit if numbers.txt is not found
    if (fin.fail()) {
        std::cerr << "The file \"numbers.txt\" does not exist. Exiting."
                  << std::endl;
        exit(1);
    }

       std::cout << "---   End Function 3 ---" << std::endl;
}


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
private:
    int digit1 = -1;
    int digit2 = -1;
    int digit3 = -1;
    int digit4 = -1;
};

void Passcode::push(int button) {
   
}

bool Passcode::valid() {
    return true;
}

void function4(){
    std::cout << "--- Begin Function 4 ---" << std::endl;
    // The valid secret code for this iPhone is 0123. 

    Passcode iPhone;
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

    std::cout << "---   End Function 4 ---" << std::endl;
}


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