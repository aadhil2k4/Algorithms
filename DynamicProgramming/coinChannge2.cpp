//Min number of coins
//Unbounded Knapsack
#include<iostream>
#include<vector>

using namespace std;

int coinChange(vector<int>&arr, int amount){
    int n = arr.size();
    vector<vector<int> >dp(n+1, vector<int>(amount+1, INT_MAX-1));
    for(int i=1; i<=n; i++){
        dp[i][0] =0;
    }
    for(int j=1; j<=amount; j++){
        if(j%arr[0]==0){
            dp[1][j] = j/arr[0];
        }else{
            dp[1][j] = INT_MAX-1;
        }
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<=amount; j++){
            if(arr[i-1]<=j){
                dp[i][j] = min(dp[i][j-arr[i-1]]+1, dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}

int main(){
    vector<int> arr = {1,2,5};
    int amount = 11;
    int ans = coinChange(arr, amount);
    cout << ans;
}