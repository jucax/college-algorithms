// Preparation for test
// First knowledge about Cpp

// INCLUDES
	// Similar to import in Java
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>


using namespace std;

// We cannot declare functions inside of main
std::string func_with_params (std::string name) {
	std::string greeting = "Welcome to Algorithms ";
	return greeting + name + ".";
}

// This is a forward declaration
int func_with_forward ();

// PASS BY VALUE FUNCTION
	void modify_by_value(int x) {  // `x` is a copy of the argument
	    x = 100;  // Changes only the copy
	    cout << "Inside function: x = " << x << endl;
	}
// PASS BY POINTER
	void modify_by_pointer(int *x) {  // `x` is a pointer to an integer
	    *x = 100;  // Modifies the value at the memory address
	    cout << "Inside function: *x = " << *x << endl;
	}

// PASS BY REFERENCE
	void modify_by_reference(int &x) {  // ✅ `x` is a reference to an integer
	    x = 100;  // Directly modifies the original variable
	    cout << "Inside function: x = " << x << endl;
	}


int main() {

	// VARIABLE TYPES
	char Character = 'c';
	string Word = "This is a string"; // String Not Capitalized
	int Integer = 1321;
	float Float = 0.002; //Single precision
	double Double = 0.218742667322; //Double precision
	long Long = 1021921092019;
	short Short = 12;
	bool boolean = true; // bool instead of boolean

	cout<< "Character: " << Character << endl;
	cout<< "String: " << Word << endl;
	cout<< "Integer: " << Integer << endl;
	cout<< "Float: " << Float << endl;
	cout<< "Double: " << Double << endl;
	cout<< "Long: " << Long << endl;
	cout<< "Short: " << Short << endl;
	cout<< "Boolean: " << boolean << endl;

	// boolalpha if istead of 1|0 we want true|false
	cout<< "Boolean: " << boolalpha << boolean << endl;

	// Instead of negative values it wrap around the max int
	unsigned int IntegerNoSymbol= -1;
	cout<< "Unsigned Integer: " << IntegerNoSymbol << endl;

	// Unsigned int for loops
		// When is from button up works as a normal loop
		for (unsigned int i = 0; i < 10; i++) {
    		cout << i << " ";
		}
		cout << endl;

		// When if from top to button, it can create and infinite loop
		/* for (unsigned int i = 10; i >= 0; i--) {
    		cout << i << " ";
		} */
		// Unsigned can be useful when:
			// - Workign with array indexes, because it will never be negative, and prevent signed-unsigned warnings

			vector<int> nums = {10, 20, 30, 40, 50};

		    for (unsigned int i = 0; i < nums.size(); i++) {  // ✅ `unsigned int avoids warnings
		        cout << nums[i] << " ";
		    }
		    cout << endl;

		    // - Working with counters downs were the count can't be negative
		    // - When usign big ranges, more than 4,000,000,000

    // NAMESPACES
    std::cout << "This is how namespaces work" << endl;

	    // :: is the scope operator, which indicate where to look for the functions
	    // std is the name of the standar library (namespace) where C++ storage the basic functions, classes and variables
	    // namespace is the name of the group of classes, functions and variables, like libraries for Java
	    // Libraries > Namespace > Classes
	    // C++ Standar Library > std Namespace > iostream Class

    // ARRAYS
    	// Whays to declare them:
    	int arr1[5]; // Specifying length
    	int arr2[5] = {0}; // Specifying initialization data
    	float arr3[] = {1, 2, 3}; // Specifying data on it
    	string arr4[] = {"Word1", "Word2"};

    	// Using arrays in C++ we dont have .size() function
    		// We have sizeof(arr): Return total memory size
    		// We have sizeof(arr[0]):Return memory size of one element
    		// Divide this two to get the number of elements in the array 

    	for (int i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++) {
    		cout << arr2[i]<< " ";
    	} 
    	cout << endl;

    	for (int i = 0; i < sizeof(arr4)/sizeof(arr4[0]); i++) {
    		cout << arr4[i]<< " ";
    	} 
    	cout << endl;

    	// Multi-dimensional arrays:
    	int matrix[5][5]; // 5 rows x 5 columns
	    	// We can leave the rows size without declaraction
	    	// We can't leave the columns size without declaration

    	int matrix2[][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    		// The [] is called subscript operator 

    	// To traverse a multi-dimensional array, we need a nested loop
    	for (int i = 0; i < sizeof(matrix2)/sizeof(matrix2[0]); i++) {
    		for (int j = 0; j < sizeof(matrix2[i])/sizeof(matrix2[i][j]); j++) {
    			cout << matrix2[i][j] << " ";
    		}
    		cout << endl;
    	}

	//	PRINTING 
    	cout << "Escape works like in Java\t I can add spacing \nstart a new line, \"Quote\" things " <<
    	"and have content in multiple lines";
    	
    	// >> and << are overload operators
    		// << to print with cout
    		// >> to save with cin

    	cout << "This wont work well" << endl;

    // FUNCTIONS
    	// Java: public int method1(){ }
    	// C++: int function1(){ }
    	// Dont need to declare the visibility

    	// We use a main function like in Java, but simpler

    	// We can't have multiple functions with the same signature
    		// Signature:
    			// Name, number of parameters, type of parameters, order of parameters
		    void sayHello();              // ✅ Function signature: sayHello()
			void sayHello(string name);   // ✅ Different signature (takes a parameter)
			void sayHello(int age);       // ✅ Different signature (different type)
			void sayHello(string name, int age); // ✅ Different signature (more parameters)

    	// We always have to return something to int main
    		// 0: exit    -1: error    1: warning

		cout << func_with_params("Juan") << endl; // Has to be declared out of main function

		// C++ have recursion like Java, some languages dont have it

		// We have to declare functions before use them
			cout << func_with_forward() << endl;
			// There are ways to use forward declaration, where we annunce about the function, 
			// So we can use the function before declare it completely 

	// LOOPS AND CONDITIONALS
		// Same like in Java
		for (int i = 3; i > -1; i--) {
			std::cout << i << " ";
		}
		cout << endl;

	// POINTERS
		// A pointer is an arrow that points to the object address
		// We can declare them using * before the name
		int *int_Pointer1 = nullptr;
		string * yellow, red, *blue;
		string y = "My favorite color is yellow";

		// Let see that each thing stores
		cout << int_Pointer1 << endl; // A null value
		cout << yellow << endl; // A random address
		cout << red << endl; // An empthy string
		cout << y << endl; // The normal string

		// If we want a pointer to hold the address of the object, we use & before the name
		yellow = &y;
		cout << yellow << endl; // The address where the string y is storaged
		cout << *yellow << endl; // The value (string) of the reference it has (dereferencing)
		cout << yellow << endl; // The adress stay the same after (dereferencing)

		// Pointers can also point to non primitive types
		int *singleInt = new int;
		int *intArray = new int[10]; // Points to the first element in the array

		// Pointer arithmetic means traverse an array using pointers
		int arrWithPointer[] = {6, 5, 4, 3, 2 ,1};
		int *arrPointer = arrWithPointer;

		cout << *arrPointer << endl; // Print the first value in the array

		for (int i = 0; i < sizeof(arrWithPointer)/sizeof(arrWithPointer[1]); i++) {
			cout << *arrPointer << " ";
			arrPointer ++;
		}
		cout << endl;

		// This works because in C++ the values in the array storage in memory locations next to each other
		// Excercise
			int myVar = 25;
			int *foo = &myVar;

			cout << myVar << " = 25" << endl; // 25 ✅
			// cout << *myVar << " = 25" << endl; // Doesn't work.
			cout << &myVar << " = 1776" << endl; // 1776 ✅
			cout << &foo << " = 25" << endl; // Randon address of pointer
			cout << foo << " = 1776" << endl; // 1776 ✅
			cout << *foo << " = 25" << endl; // 25 ✅

	// MEMORY
		// In C++ we don't have automatical garbage collection, 
		// So we need to take care of how we use the memory
			// After we declare varaibles using the new word, we can delete them from the memory

			delete singleInt;
			delete [] intArray;
		// Normal varaibles like:
			// Local variables:
			int variable = 1; // Storage in stack, and are removed automatically when they are out of scope
			// Also the ones declared within a method

			// Pointer varaible:
			int *pointer = new int(1); // Storage pointer in stack, but value in heap
			// Even if we dont use if the value stays in heap until we explicity remove it


	// PASS VALUES IN C++
		// Pass-by-value
			// When value is given to a function
			// C++ creates a copy of the argument, so changes made within the function doesn't change
			// the original variable
			int num = 10;
		    modify_by_value(num);  // Passes `num` by value (a copy is created)
		    cout << "After function by value: num = " << num << endl;  // `num` remains unchanged

		// Pass-by-pointer
		    // When a pointer to a variable is given to a function
		    // C++ has direct access to the original variable, so it can modify it from the function
		    modify_by_pointer(&num); // Passes pointer of 'num2', no copy created
		    cout << "After function by pointer: num = " << num << endl; // `num` is changed

		// Pass-by-reference
		    // When a reference to a variable is given to a function
		    // C++ has direct access to the priginal varaible, so it can modigy if from the function
		    modify_by_reference(num); // Passes `num` by reference
		    cout << "After function by reference: num = " << num << endl; // `num` is changed

  	return 0;
}


// We can declare after use a function if we use forward declaration
int func_with_forward () {
	return 3;
}

// CLASSES
		// Classes doesn't need to have the same name as the file
		class Cat {
		private:
			string breed, name;
		public:
			Cat(string, string); // Constructor declaration, i could also define the consutrcture inside the class.
			void pounce(); // Function declaration, without definition

			void printInfo() {
				cout << name << "is a" << breed << endl;
			} //  We can also define the functions here

			Cat operator + (const Cat&); // We can declare an operator to define it later
		}; // End class definition with ;

		// Define constructor outsite the class
		Cat::Cat(string n, string b) {
			name = n;
			breed = b;
		}

		// Define functions outsite the class
		void Cat::pounce() {
			cout << "Your cat pounces." << endl;
		}
		// First Cat, the return type
		// Second Cat pointing to Cat class
		// We use Cat& because we reference the address, and we don't have to create a copy
		// Then we use const type, because that way we make sure we don't change data in it

		// We can define the functionality of operators, this is call operator overloading
		Cat Cat::operator+(const Cat& param) { 
			Cat temp("Mixed", "Mixed");
			temp.breed = breed + "-" + param.breed;
			temp.name = name + "-" + param.name;
			return temp;
		}

		// cat1 is on the left → This means cat1 is the object calling the operator+() function.
		// cat2 is on the right → This is the parameter passed to the function.
		// It just combine the names and the breed of the two cats 

		// All the functions in this clase are member functions, because are defined within the class
		// It doesn't matter where the definition happens, with the :: we can define after the class

		// A free function, is not part of a class, different from Java, where everything is inside a class


































