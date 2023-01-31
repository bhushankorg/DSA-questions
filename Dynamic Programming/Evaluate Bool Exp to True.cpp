#include <bits/stdc++.h> 
#define ll long long

int mod = (int)1e9 + 7;
ll findWays(int i, int j, bool isTrue, string &exp, vector<vector<vector<ll>>> &dp){
    if(i > j) return 0;
    if(i == j) {
        if(isTrue) return (exp[i] == 'T');
        else return (exp[i] == 'F');
    }
    
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    for(int k = i; k <= j - 2; k += 2){
        ll LT = findWays(i, k, 1, exp, dp);
        ll RT = findWays(k + 2, j, 1, exp, dp);
        ll LF = findWays(i, k, 0, exp, dp);
        ll RF = findWays(k + 2, j, 0, exp, dp);
        char op = exp[k + 1];
        
        if(op == '&'){
            if(isTrue) ways =  (ways % mod + (LT * RT) % mod) % mod;
            else ways = (ways % mod + (LT * RF) % mod + (LF * RT) % mod + (LF * RF) % mod) % mod;
        }
        // 0 | 0 = 0 else true 
        else if(op == '|'){
            if(isTrue) ways = (ways % mod + (LT * RF) % mod + (LF * RT) % mod + (LT * RT) % mod) % mod;
            else ways = (ways % mod + (LF * RF) % mod) % mod;
        }
        else{
            if(isTrue) ways = (ways % mod + (LF * RT) % mod + (LT * RF) % mod) % mod;
            else ways = (ways % mod + (LT * RT) % mod + (LF * RF) % mod) % mod;
        }
    }
    
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.length();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return (int)findWays(0, n - 1, 1, exp, dp);
}