#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

int trappingWater(int arr[], int n) {
	int leftMax[n];
	int rightMax[n];
	leftMax[0] = arr[0];
	rightMax[n - 1] = arr[n - 1];
	for (int i = 1; i < n; i++)	{
		leftMax[i] = max(arr[i], leftMax[i - 1]);
		rightMax[n - 1 - i] = max(arr[n - 1 - i], rightMax[n - i]);
	}
	
	int water = 0;
	for (int i = 0; i < n; i++)	{
		water += min(leftMax[i], rightMax[i]) - arr[i];
	}
	return water;
}

int main() {
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++)	{
		cin >> arr[i];
	}

	cout << trappingWater(arr, n);

	return 0;
}