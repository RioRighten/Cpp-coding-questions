#include <iostream>
#include <stdexcept>  // For std::runtime_error
using namespace std;

// Function to perform division
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        throw runtime_error("Error: Division by zero!");  // Throw an exception for division by zero
    }
    return numerator / denominator;
}

int main() {
    double num, denom;

    cout << "Enter numerator: ";
    cin >> num;
    cout << "Enter denominator: ";
    cin >> denom;

    try {
        double result = divide(num, denom);  // Attempt to perform division
        cout << "Result: " << result << endl;
    } catch (const runtime_error& e) {
        cout << e.what() << endl;  // Catch and display the error message
    }

    return 0;
}
