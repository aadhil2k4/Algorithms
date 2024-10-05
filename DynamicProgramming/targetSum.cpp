//01 knapsack based
#include<iostream>
#include<vector>

using namespace std;

int targetSum(vector<int>&nums, int target){
    int n =nums.size();
    int sum=0;
    for(int i:nums){
                sum+=i;
    }
    if((sum+target)%2!=0 || sum<target || (sum+target)<0){
        return 0;
    }
    int sum1 = (target+sum)/2;
    vector<vector<int> > dp(n+1, vector<int>(sum1+1, 0));
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0;j<=sum1;j++){
            if(nums[i-1]<=j){
                dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum1];
}

int main(){
    vector<int>nums = {1,1,1,1,1};
    int target = 3;
    int ans = targetSum(nums, target);
    cout << ans;
}