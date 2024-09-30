#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<int>& arr){
    for(int i=1; i<arr.size(); i++){
        int key = arr[i];   
        int j = i-1;    
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    vector<int> arr; 
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        int element;
        cin >> element;  
        arr.push_back(element);  
    }
    insertionSort(arr);
    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;
    return 0;
}