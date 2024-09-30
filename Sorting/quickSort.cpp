#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of the smaller element
    // Loop through the array, rearranging elements based on the pivot
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {       // If the current element is smaller than the pivot
            i++;                    // Move the smaller element index forward
            swap(arr[i], arr[j]);   // Swap the current element with the smaller element
        }
    }
    // Place the pivot in its correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return the pivot index
}

// Function to perform Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);
        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);  // Sort the left part
        quickSort(arr, pi + 1, high); // Sort the right part
    }
}

int main() {
    vector<int> arr;  // Initialize an empty vector to store integers
    int n;

    // Step 1: Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Step 2: Input elements from the user
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;   // Input each element
        arr.push_back(element);  // Add the element to the vector
    }

    // Step 3: Call quick sort on the vector
    quickSort(arr, 0, arr.size() - 1);

    // Step 4: Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  // Print each sorted element
    }
    cout << endl;

    return 0;  // Indicate successful completion of the program
}
