//https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1?page=1&difficulty[]=1&status[]=unsolved&category[]=Strings&curated[]=1&curated[]=7&sortBy=submissions
//String, Sliding window

//make map of distinct characters
//create a counter, increment right pointer till counter is equal to distinct characters
//increment left pointer till only single char is remaining reduce counter if drops to zero
//keep updating min(minWindow, j-i)
//repeat this process till i <= j and j < n

#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

int findSubString(string str) {
	unordered_set<char>st(str.begin(), str.end());
	map<char, int> mp;
	int n = str.length();

	int count = 1
	int i = 0;
	int j = 1;
	mp[str[0]]++;
	int minIndex = INT_MAX;

	while (i <= j && j < n) {
		if (count < st.size()) {
			if (mp[str[j]] == 0) count++;
			mp[str[j]]++;
			j++;
		}
		else if (count == st.size()) {
			minIndex = min(minIndex, j - i);
			if (mp[str[i]] == 1) count--;
			mp[str[i]]--;
			i++;
		}
	}

	while (count == st.size()) {
		minIndex = min(minIndex, j - i);
		if (mp[str[i]] == 1) count--;
		mp[str[i]]--;
		i++;
	}

	return minIndex;
}

int main() {
	string str;
	cin >> str;

	cout << findSubString(str);

	return 0;
}