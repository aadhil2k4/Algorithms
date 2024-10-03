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

int tabulate(vector<int>&wt, vector<int>&val, int w,int n){
    vector<vector<int>>t(n+1, vector<int>(w+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
            if(wt[i-1]<=j){
                t[i][j] = max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            }
            else if(wt[i-1]>j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}

int main(){
    int n, w;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> wt(n), val(n);
    cout << "Enter the weight and value of each item:\n";
    for(int i = 0; i < n; i++){
        cin >> wt[i] >> val[i];
    }
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> w;
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    cout << "Maximum value using recursion: " << recursive(wt, val, w, n) << endl;
    cout << "Maximum value using memoization: " << memoize(wt, val, w, n, dp) << endl;
    cout << "Maximum value using tabulation: " << tabulate(wt, val, w, n) << endl;
    return 0;
}