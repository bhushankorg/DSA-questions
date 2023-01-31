//https://practice.geeksforgeeks.org/problems/max-length-chain/1
//DP Greddy Famous approach sort by pair.second and save last second for comparing next valid first

#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

struct val {
	int first;
	int second;
};

bool comp(struct val n1, struct val n2) {
	return n1.second < n2.second;
}

int maxChainLen(struct val p[], int n) {
	int count = 1;
	sort(p, p + n, comp);
	int currLast = p[0].second;
	
	for (int i = 1; i < n; i++)	{
		if(currLast < p[i].first){
			count++;
			currLast = p[i].second;
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;

	struct val p[n];

	for (int i = 0; i < n; i++)	{
		cin >> p[i].first >> p[i].second;
	}

	cout << maxChainLen(p, n);

	return 0;
}