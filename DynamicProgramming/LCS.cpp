#include<iostream>
#include<vector>

using namespace std;

int recursive(string x, string y, int n, int m){
    if(n==0 ||m==0){
        return 0;
    }
    if(x[n-1]==y[m-1]){
        return 1 + recursive(x,y,n-1,m-1);
    }
    else{
        return max(recursive(x,y,n-1,m),recursive(x,y,n,m-1));
    }
}

int memoize(string x, string y, int n, int m, vector<vector<int> >&dp){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(x[n-1]==y[m-1]){
        return dp[n][m] = 1 + memoize(x,y,n-1,m-1,dp);
    }else{
        return dp[n][m] = max(memoize(x,y,n-1,m,dp),memoize(x,y,n,m-1,dp));
    }
}

int tabulate(string x, string y, int n, int m){
    vector<vector<int> >dp(n+1, vector<int>(m+1,-1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<=n;i++){
        for(int j=1;j<=m; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}



int main(){
    string x = "abcde";
    string y = "ace";
    int n = x.length();
    int m = y.length();
    cout << "LCS (Recursive): " << recursive(x, y, n, m) << endl;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << "LCS (Memoization): " << memoize(x, y, n, m, dp) << endl;
    cout << "LCS (Tabulation): " << tabulate(x, y, n, m) << endl;
}