// search min difference element in sorted array
#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

int minDiff(vector<int>&nums, int n, int key) {
	int start = 0, end = n - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] == key) {
			return mid;
		}
		else if (nums[mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	if (abs(key - nums[start]) < abs(key - nums[end])) {
		return start;
	}
	return end;
}

int main() {
	int n;
	cin >> n;

	vector<int>nums(n);

	for (int i = 0; i < n; i++)	{
		cin >> nums[i];
	}

	cout << minDiff(nums, n, 12);

	return 0;
}
