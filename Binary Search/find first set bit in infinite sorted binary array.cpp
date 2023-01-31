// find first set bit in infinite sorted binary array
#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

int binary_search(int start, int end, vector<int>&nums1) {
	int res = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums1[mid] == 0) {
			start = mid + 1;
		}
		else {
			res = mid;
			end = mid - 1;
		}
	}
	return res;
}

int searchIndex(vector<int>&nums1) {
	int start = 0, range = 1;
	int end = start + range;

	while (nums1[range] == 0) {
		range *= 2;
		start = end;
		end = range;
	}
	return binary_search(start, end, nums1);
}
int main() {
	int m, n;
	cin >> m ;

	vector<int>nums1(m);
	//vector<int>nums2(n);

	for (int i = 0; i < m; i++)	{
		cin >> nums1[i];
	}
	/*
		for (int i = 0; i < n; i++)	{
			cin >> nums2[i];
		}*/

	/*for (int i : intersect(nums1, nums2)) {
		cout << i << " ";
	}*/

	cout << searchIndex(nums1);

	return 0;
}