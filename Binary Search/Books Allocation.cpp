// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

bool isValid(vector<int>books, int n, int limit, int maxStudents) {
	int students = 1;
	int sum = 0;
	for (int i = 0; i < n; i++)	{
		if (sum + books[i] > limit) {
			sum = books[i];
			students++;
		}
		else {
			sum += books[i];
		}
	}
	return (students <= maxStudents);
}

int minPages(int n, vector<int>books, int k) {
	int start = 0;
	int end = 0;
	int res = 0;
	for (int i = 0; i < n; i++)	{
		start = max(start, books[i]);
		end += books[i];
	}

	while (start <= end) {
		int mid = (start + end) >> 1;
		if (isValid(books, n, mid, k)) {
			res = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return res;
}

int main() {
	int n, k;
	cin >> n;
	vector<int>books(n);

	for (int i = 0; i < n; i++)	{
		cin >>	books[i];
	}

	cin >> k;

	cout << minPages(n, books, k);

	return 0;
}