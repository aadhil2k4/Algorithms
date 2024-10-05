//Max number of ways
//Unbounded Knapsack
#include<iostream>
#include<vector>

using namespace std;

int coinChange(vector<int>&coins, int amount){
    int n = coins.size();
    vector<vector<int> > dp(n+1, vector<int>(amount+1,0));
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n; i++){
        for(int j=1; j<=amount; j++){
            if(coins[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}

int main(){
    vector<int>coins = {1,2,5};
    int amount = 11;
    int ans = coinChange(coins, amount);
    cout << ans;
}