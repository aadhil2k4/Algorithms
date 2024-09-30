#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int>& arr, int x){
    int left=0;
    int right= arr.size()-1;
    while(left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid]==x){
            return mid;
        }else if(arr[mid]<x){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}