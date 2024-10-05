//unbounded Knapsack based
#include<iostream>
#include<vector>

using namespace std;

int rodCut(vector<int>&price,int n){
    int sz = price.size();
    vector<vector<int> >dp(n+1, vector<int>(sz+1,0));
    //Maximum value obtained with rod length j and price upto i
    //i--->current piece length
    //j--->current total rod length
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sz; j++){
            if(i<=j){//check if current piece can fit in rod
                dp[i][j] = max(price[i-1]+dp[i][j-i], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sz];
}

int main(){
    vector<int>price = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = 8;
    int ans = rodCut(price, N);
    cout << ans;
}