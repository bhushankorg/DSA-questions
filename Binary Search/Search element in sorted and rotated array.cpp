#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

int searchRotated(vector<int>&nums, int key) {
	int start = 0;
	int end = nums.size() - 1;

	while (start <= end) {
		int mid = (start + end) >> 1;
		if (nums[mid] == key)
			return mid;

		if (nums[start] < nums[mid]) {
			if (key >= nums[start] && key <= nums[mid - 1]) {
				end = mid - 1;
			}
			else
				start = mid + 1;
		}
		else {
			if (key >= nums[mid + 1] && key <= nums[end]) {
				start = mid + 1;
			}
			else
				end = mid - 1;
		}
	}
	return -1;
}

int main() {
	int n, key;
	cin >> n >> key;

	vector<int>nums(n);

	for (int i = 0; i < n; i++)	{
		cin >> nums[i];
	}

	cout << searchRotated(nums, key);

	return 0;
}