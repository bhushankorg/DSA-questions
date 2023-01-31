//https://practice.geeksforgeeks.org/problems/rotation4723/1/#
#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

int findKRotation(int arr[], int n) {
	int start = 0, end = n - 1, mid;

	while (start <= end) {
		if (arr[start] < arr[end]) {
			return start;
		}
		mid = start + (end - start) / 2;
		int prev = (mid + n - 1) % n;
		int next = (mid + 1) % n;

		if (arr[mid] < arr[prev] && arr[mid] < arr[next]) {
			return mid;
		}
		else if (arr[start] <= arr[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return mid;
}

int main() {
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
	}

	cout << findKRotation(arr, n);

	return 0;
}