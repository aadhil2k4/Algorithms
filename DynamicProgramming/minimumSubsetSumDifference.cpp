#include<iostream>
#include<vector>

using namespace std;

int minDiff(vector<int>&arr){
    int n = arr.size();
    int range = 0;
    vector<int>subset;
    for(int i: arr){
        range+=i;
    }
    vector<vector<bool> >dp(n+1, vector<bool>(range/2+1, false));
    for(int i=0;i<=n; i++){
        dp[i][0] = true;
    }
    subset.push_back(0);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=range/2; j++){
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            if(dp[i][j]==true){
                subset.push_back(j);
            }
        }
    }
    int min_num = INT_MAX;
    for(int i: subset){
        min_num = min(min_num, range-2*i);
    }
    return min_num;
}

int main(){
    vector<int>arr = {1,2,7};
    int ans;
    ans = minDiff(arr);
    cout << ans;
}