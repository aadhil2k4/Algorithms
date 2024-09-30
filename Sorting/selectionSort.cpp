#include<iostream>
#include<vector>

using namespace std;

void selectionSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

int main(){
    vector<int> arr = {64, 25, 12, 22, 11};
    
    cout << "Original array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    
    selectionSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;
    
    return 0;
}