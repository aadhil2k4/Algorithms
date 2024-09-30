#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int>&arr, int left, int mid, int right){
    int n1 = mid-left+1;
    int n2 = right-mid;
    //Temporary vectors for left and right subarrays
    vector<int>L(n1), R(n2);
    //Copy data to temporary arrays
    for(int i=0; i<n1; i++){
        L[i] = arr[left+i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[mid+1+j];
    }
    //initial index of 2 subarrays
    int i=0, j=0;
    //initial index of merged array
    int k = left;
    //Merge temporary arrays into original array
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //Copy remaining elements of array
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = L[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>&arr, int left, int right){
    if(left<right){
        //find mid point
        int mid = (left+right)/2;
        //Recursively sort first and second half
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        //merge sorted halves
        merge(arr, left, mid, right);
    }
}

int main(){
    vector<int> arr;  // Initialize an empty vector to store integers
    int n;

    // Step 1: Input the number of elements in the array
    cout << "Enter the number of elements: ";
    cin >> n;

    // Step 2: Input elements from the user
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        arr.push_back(element);  // Add the element to the vector
    }

    // Step 3: Call merge sort on the vector
    mergeSort(arr, 0, arr.size() - 1);

    // Step 4: Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";  // Print each sorted element
    }
    cout << endl;

    return 0;
}