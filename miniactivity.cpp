#include <iostream>
#include <limits>

using namespace std;

// Function to modify the value of a specific element in the array
void modifyElement(int arr[], int size, int index, int newValue) {
    if (index >= 0 && index < size) {
        arr[index] = newValue;
        cout << "Element at index " << index << " has been updated to " << newValue << ".\n";
    } else {
        cout << "Index out of bounds.\n";
    }
}

// Function to find the minimum and maximum values in the array
void findMinMax(const int arr[], int size, int& minValue, int& maxValue) {
    if (size <= 0) {
        cout << "Array is empty.\n";
        return;
    }
    
    minValue = numeric_limits<int>::max();
    maxValue = numeric_limits<int>::min();
    
    for (int i = 0; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    // Ensure the size is positive
    if (n <= 0) {
        cout << "Invalid array size.\n";
        return 1;
    }
    
    int* arr = new int[n];  // Dynamically allocate array
    
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    // Display the initial array
    cout << "Array elements are: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Modify an element
    int index, newValue;
    cout << "Enter the index of the element to modify: ";
    cin >> index;
    cout << "Enter the new value: ";
    cin >> newValue;
    
    modifyElement(arr, n, index, newValue);
    
    // Display the modified array
    cout << "Modified array elements are: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Find min and max
    int minValue, maxValue;
    findMinMax(arr, n, minValue, maxValue);
    
    cout << "Minimum value in the array: " << minValue << endl;
    cout << "Maximum value in the array: " << maxValue << endl;
    
    delete[] arr;  // Free the allocated memory
    return 0;
}