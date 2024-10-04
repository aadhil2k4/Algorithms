//01 Knapsack based
#include<iostream>
#include<vector>

using namespace std;

bool subsetSum(vector<int>& arr, int sum){
    int n= arr.size();
    vector<vector<int> >dp(n+1, vector<int>(sum+1,false));
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum;j++){
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
