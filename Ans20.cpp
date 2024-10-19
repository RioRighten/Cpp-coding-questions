#include <iostream>
using namespace std;

// Function to perform binary search recursively
int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;  // Calculate mid index

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid;  // Return the index if found
        }

        // If target is smaller than mid, search in the left subarray
        if (arr[mid] > target) {
            return binarySearch(arr, left, mid - 1, target);
        }

        // Otherwise, search in the right subarray
        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;  // Return -1 if the target is not found
}

int main() {
    int n, target;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n];  // Dynamically allocate array

    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target element to search for: ";
    cin >> target;

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, target);

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    delete[] arr;  // Free the dynamically allocated memory
    return 0;
}
