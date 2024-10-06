#include<iostream>
#include<vector>

using namespace std;

int lps(string x,int n){
    string y = "";
    for(int i=n-1; i>=0; i--){
        y += x[i];
    }
    vector<vector<int> >dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
    string x = "agbcba";
    int n = x.length();
    int ans = lps(x,n);
    cout << ans;
}