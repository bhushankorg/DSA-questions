//https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1
//DP Recursion Memorization 
//Make choice which gives best reduce array from front or back, opponents choice will give me least possible amount.
//Since the i j could be same, apply memorization

#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

int findAmount(vector<int>&A, int front, int back, vector<vector<int>>&dp) {
	if (front == back) return A[front];

	if (front + 1 == back) return max(A[front], A[back]);

	if (dp[front][back] != -1) return dp[front][back];

	int start = A[front] + min(findAmount(A, front + 2, back, dp), findAmount(A, front + 1, back - 1, dp));
	int end = A[back] + min(findAmount(A, front + 1, back - 1, dp), findAmount(A, front, back - 2, dp));

	return dp[front][back] = max(start, end);
}

int maxCoins(vector<int>&A, int n){
	vector<vector<int>>dp(n, vector<int>(n, -1));
	
	return findAmount(A, 0, n - 1, dp);
}

int main() {
	int n;
	cin >> n;

	vector<int>arr(n);

	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
	}

	cout << maxCoins(arr, n);

	return 0;
}