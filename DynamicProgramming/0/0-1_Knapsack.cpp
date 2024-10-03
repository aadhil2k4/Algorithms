#include<iostream>
#include<vector>

using namespace std;

int recursive(vector<int> &wt, vector<int>&val, int w, int n){
    //Base Condition
    if(n==0 || w==0){
        return 0;
    }
    //Select item
    if(wt[n-1]<=w){
        return max(val[n-1]+ recursive(wt, val, w-wt[n-1], n-1), recursive(wt, val, w, n-1));
    }
    //Reject item
    else if(wt[n-1]>w){
        return recursive(wt, val, w, n-1);
    }
}



int main(){

}