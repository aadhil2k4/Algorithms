#include<iostream>
#include<vector>

using namespace std;

int recursive(vector<int> &wt, vector<int>&val, int w, int n){
    //Base Condition
    if(n==0 || w==0){
        return 0;
    }
    //Item can be selected
    if(wt[n-1]<=w){
        return max(val[n-1]+ recursive(wt, val, w-wt[n-1], n-1), recursive(wt, val, w, n-1));
    }
    //Reject item
    else if(wt[n-1]>w){
        return recursive(wt, val, w, n-1);
    }
}

int memoize(vector<int>&wt, vector<int>&val, int w, int n, vector<vector<int>>&dp){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(wt[n-1]<=w){
        dp[n][w] = max(val[n-1]+memoize(wt,val,w-wt[n-1],n-1,dp), memoize(wt,val,w,n-1,dp));
    }
    else if(wt[n-1]>w){
        dp[n][w] = memoize(wt,val,w,n-1,dp);
    }
    return dp[n][w];
}

int main(){

}