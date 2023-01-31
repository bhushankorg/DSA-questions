	#include <bits/stdc++.h>
	using namespace std;
	#define INT_MIN_VALUE -2147483648
	#define INT_MAX_VALUE 2147483647

	int palindrome(string str, int i, int j, vector<vector<int>>&dp) {
		if (i >= j)
			return dp[i][j] = 1;

		if (dp[i][j] != -1)
			return dp[i][j];

		if (str[i] != str[j])
			return dp[i][j] = 0;

		return palindrome(str, i + 1, j - 1, dp);
	}

	int palindromeSubStrs(string str) {
		int n = str.length();
		set <string> ansset;

		vector<vector<int>> dp(n, vector<int>(n, -1));

		for (int i = 0; i < str.length(); i++) {
			for (int j = i; j < str.length(); j++) {
				//cout << substring(str, i, j ) << endl;
				if (palindrome(str, i, j, dp) == 1) {
					//dp[i][j] = 1;
					//cout << str.substr(i, j + 1) << endl;
					ansset.insert(str.substr(i, j - i + 1));
				}
			}
		}/*
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < str.length(); j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/

		return ansset.size();
	}

	int main() {
		string str ;
		cin >> str;

		cout << palindromeSubStrs(str);

		return 0;
	}