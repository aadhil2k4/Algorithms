//LCS based
#include<iostream>
#include<vector>

using namespace std;

int subString(string x, string y, int n, int m){
    vector<vector<int> >dp(n+1, vector<int>(m+1, -1));
    int maxLen =0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(dp[i][j], maxLen);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    return maxLen;
}

int main(){
    string x = "abcde";
    string y = "abfce";
    int n = x.length();
    int m = y.length();
    int ans = subString(x,y,n,m);
    cout << ans;
}