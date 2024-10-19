#include <iostream>
using namespace std;

// Function to find the maximum value in the array
int findMax(int* arr, int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find the minimum value in the array
int findMin(int* arr, int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int size;

    cout << "Enter the number of elements: ";
    cin >> size;

    // Dynamically allocate memory for the array
    int* arr = new int[size];

    cout << "Enter " << size << " integers:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Find and display the max and min values
    int maxVal = findMax(arr, size);
    int minVal = findMin(arr, size);

    cout << "Maximum Value: " << maxVal << endl;
    cout << "Minimum Value: " << minVal << endl;

    // Free the allocated memory
    delete[] arr;

    return 0;
}
