#include<iostream>
#include<vector>

using namespace std;

void insertionSort(vector<float>&bucket){
    for(int i=1; i<bucket.size(); i++){
        float key = bucket[i];
        int j = i-1;
        while(j>=0 && bucket[j]>key){
            bucket[j+1] = bucket[j];
            j--;
        }
        bucket[j+1] = key;
    }
}

void bucketSort(float arr[], int n){
    vector<float> buckets[n];
    for(int i=0; i<n; i++){
        int bucketIndex = n*arr[i]; 
        buckets[bucketIndex].push_back(arr[i]); 
    }
    for(int i=0; i<n; i++){
        insertionSort(buckets[i]);
    }
    int index = 0;  
    for(int i=0; i<n; i++){
        for(float value : buckets[i]){
            arr[index++] = value;   
        }
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}