//nearly sorted array
#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

int maxSubArray(vector<int>& nums, int key) {
	int start = 0, end = nums.size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[mid] == key) {
			return mid;
		}
		if (mid - 1 >= start && nums[mid - 1] == key) {
			return mid - 1;
		}
		if (mid + 1 <= end && nums[mid + 1] == key) {
			return mid + 1;
		}
		else if (nums[mid] < key) {
			start = mid + 2;
		}
		else {
			end = mid - 2;
		}
	}
	return -1;
}


int main() {
	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
	}

	cout << maxSubArray(arr, 700);

	return 0;
}