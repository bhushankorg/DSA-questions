//https://practice.geeksforgeeks.org/problems/palindrome-pairs/1#
#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

bool isPallindrome(string str) {
	int start = 0;
	int end = str.length() - 1;
	while (start < end) {
		if (str[start] != str[end]) {
			return false;
		}
		start++;
		end--;
	}
	return true;
}

string rev(string s) {
	string a = s;
	reverse(a.begin(), a.end());
	return a;
}

bool palindromepair(int n, string arr[]) {
	map<string, int>mp;
	for (int i = 0; i < n; i++)	{
		mp[arr[i]] = i;
	}

	for (int i = 0; i < n; i++)	{
		string str = arr[i];
		if (mp.find(rev(str)) != mp.end() && mp[rev(str)] != i) {
			return true;
		}
		for (int j = 1; j < str.length(); j++)	{
			string str1 = str.substr(0, j);
			string str2 = str.substr(j, (str.length() - j));
			if (isPallindrome(str1) && mp.find(rev(str2)) != mp.end()) {
				return true;
			}
			if (isPallindrome(str2) && mp.find(rev(str1)) != mp.end()) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	string arr[n];

	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
	}

	cout << palindromepair(n, arr);

	return 0;
}