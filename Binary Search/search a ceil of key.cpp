#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

int calcFloor(vector<int>&nums, int key) {
	int start = 0;
	int end = nums.size() - 1;
	int res = 0;

	while (start <= end) {
		int mid = (start + end) >> 1;
		if (nums[mid] == key)
			return mid;
		else if (nums[mid] > key) {
			res = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;

	}
	return res;
}

int main() {
	int n, key;
	cin >> n >> key;

	vector<int>nums(n);

	for (int i = 0; i < n; i++)	{
		cin >> nums[i];
	}

	cout << calcFloor(nums, key);

	return 0;
}