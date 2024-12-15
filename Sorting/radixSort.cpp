#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Function to perform Counting Sort based on the current digit (exp)
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);  // Output array to store sorted elements
    vector<int> count(10, 0);  // Count array to store frequency of digits

    // Count the frequency of each digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] to store the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[] to reflect the sorted order
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());  // Find the maximum number to determine the number of digits

    // Perform counting sort for every digit. The exp is 10^i where i is the current digit number.
    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    // Perform Radix Sort on the array
    radixSort(arr);

    // Output the sorted array
    cout << "Sorted Array: ";
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
