#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void countingSort(vector<int>&arr, int exp){
    int n = arr.size();
    vector<int>output(n);
    vector<int>count(10,0);
    for(int i=0; i<n; i++){
        count[(arr[i]/exp)%10]++;
    }
    
}

int main(){

}