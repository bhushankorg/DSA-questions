#include <bits/stdc++.h> 
int findMinSteps(int i, int j, vector<int> &arr, vector<vector<int>> &dp){
    if(i == j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int mini = 1e9;
    for(int k = i; k < j; k++){
        int steps = arr[i - 1] * arr[k] * arr[j] + findMinSteps(i, k, arr, dp) + 
            findMinSteps(k + 1, j, arr, dp);
        mini = min(steps, mini);
    }
    
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return findMinSteps(1, N - 1, arr, dp);
}