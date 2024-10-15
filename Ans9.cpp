#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    cout << "Max: " << max << ", Min: " << min << endl;
    delete[] arr;
    return 0;
}
