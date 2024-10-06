//LCS based
#include<iostream>
#include<vector>

using namespace std;

int sublength(string x, string y, int n, int m){
    vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return m+n-dp[n][m];
}

int main(){
    string x = "aggtab";
    string y = "gxtxayb";
    int n = x.length();
    int m = y.length();
    int ans = sublength(x,y,n,m);
    cout << ans;
}