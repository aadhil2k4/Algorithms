//LCS based
#include<iostream>
#include<vector>

using namespace std;

void printString(string x, string y, int n, int m, vector<vector<int> >dp){
    int i=n, j=m;
    string s="";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            s+=x[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j]>dp[i][j-1]){
                s+=x[i-1];
                i--;
            }else{
                s+=y[j-1];
                j--;
            }
        }
    }
    while(i>0){
        s+=x[i-1];
        i--;
    }
    while(j>0){
        s+=y[j-1];
        j--;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

void lcs(string x, string y, int n, int m){
    vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    printString(x,y,n,m,dp);
}

int main(){
    string x = "acbcf";
    string y = "abcdaf";
    int n = x.length();
    int m = y.length();
    lcs(x,y,n,m);
}