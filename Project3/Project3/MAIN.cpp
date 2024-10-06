#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

// Function declarations
bool isNumber(const string& str);        // Declares the isNumber function
bool isMathSymbol(const string& str);    // Declares the isMathSymbol function

// Main function
int main() {
    string input;
    cout << "Enter a series of numbers or math symbols, separated by spaces: ";
    getline(cin, input);

    // Using stringstream to split the input based on spaces
    stringstream ss(input);
    string token;

    while (ss >> token) {
        if (isNumber(token)) {
            cout << "'" << token << "' is a number." << endl;
        }
        else if (isMathSymbol(token)) {
            cout << "'" << token << "' is a math symbol." << endl;
        }
        else {
            cout << "'" << token << "' is neither a number nor a valid math symbol." << endl;
        }
    }

    return 0;
}

// Function definitions

// Definition of isNumber function
bool isNumber(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {  // Check if each character is a digit
            return false;
        }
    }
    return !str.empty();    // Ensures that the string is not empty
}

// Definition of isMathSymbol function
bool isMathSymbol(const string& str) {
    return (str == "+" || str == "-" || str == "*" || str == "/");   // Checks if the string matches any valid math symbol
}
