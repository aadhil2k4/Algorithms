//01 Knapsack based
#include<iostream>
#include<vector>

using namespace std;

bool subsetSum(vector<int>& arr, int sum){
    int n= arr.size();
    vector<vector<int>>dp(n+1, vector<int>(sum+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum;j++){
            if(i==0){
                dp[i][j] = true;
            }else if(j==0){
                dp[i][j] = false;
            }
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    vector<int>arr = {2,3,7,8,10};
    int sum = 11;
    bool ans;
    ans = subsetSum(arr, sum);
    cout << ans;
}
