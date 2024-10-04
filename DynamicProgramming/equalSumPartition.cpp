//01 knapsack based
#include<iostream>
#include<vector>

using namespace std;

bool partition(vector<int>&arr){
    int sum=0;
    for(int i: arr){
        sum+=i;
    }
    if(sum%2!=0){
        return false;
    }
    int n = arr.size();
    vector<vector<int> >dp(n+1,vector<int>(sum/2+1, false));
    for(int i=0; i<=n; i++){
        dp[i][0] = true;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum/2;j++){
            if(arr[i-1]<=sum/2){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum/2];
}

int main(){
    vector<int>arr = {1,5,11,5};
    bool ans;
    ans = partition(arr);
    cout << ans;
}