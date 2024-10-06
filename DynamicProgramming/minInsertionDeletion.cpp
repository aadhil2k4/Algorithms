//string A ---> string B
#include<iostream>
#include<vector>

using namespace std;

int operate(string x, string y, int n, int m){
    vector<vector<int> >dp(n+1, vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int del = abs(n-dp[n][m]);
    int ins = abs(dp[n][m]-m);
    return del+ins;
}

int main(){
    string x = "heap";
    string y = "pea";
    int n = x.length();
    int m = y.length();
    int ans = operate(x,y,n,m);
    cout << ans;
}