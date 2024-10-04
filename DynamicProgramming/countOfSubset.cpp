#include<iostream>
#include<vector>

using namespace std;

int countSubset(vector<int>&arr){
    int n = arr.size();
    int sum=0;
    for(auto i: arr){
        sum+=i;
    }
    if(sum%2!=0){
        return 0;
    }
    vector<vector<int> >dp(n+1, vector<int>(sum/2+1, 0));
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum/2; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
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
    int ans;
    ans = countSubset(arr);
    cout << ans;
}