#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm> 
using namespace std;


double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw invalid_argument("Division by zero.");
    }
    return a / b;
}

double calculate(const string& operation, double a, double b) {
    if (operation == "add") {
        return add(a, b);
    } else if (operation == "subtract") {
        return subtract(a, b);
    } else if (operation == "multiply") {
        return multiply(a, b);
    } else if (operation == "divide") {
        return divide(a, b);
    } else {
        throw invalid_argument("Invalid operation: " + operation);
    }
}


int main() {
    cout << "Welcome to the Calculator App!" << endl;
    cout << "Available operations: add, subtract, multiply, divide" << endl;

    string operation;
    double a, b;

    try {
        cout << "Enter first number: ";
        if (!(cin >> a)) {
            throw invalid_argument("Invalid input for the first number.");
        }

        cout << "Enter second number: ";
        if (!(cin >> b)) {
            throw invalid_argument("Invalid input for the second number.");
        }

        cin.ignore(); 
        cout << "Enter operation: ";
        getline(cin, operation);
        
        operation.erase(remove(operation.begin(), operation.end(), ' '), operation.end());

        double result = calculate(operation, a, b);
        cout << "The result is: " << result << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
