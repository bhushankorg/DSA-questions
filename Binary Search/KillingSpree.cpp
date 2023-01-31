//https://practice.geeksforgeeks.org/problems/killing-spree3020/1#
//This was binary search question which I solved in first attempt without watching any videoes 04 May 2022
#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

long long int killinSpree(long long int n) {
	long long int start = 1, end = ceil(sqrt(n));
	long long int res = 0;

	while (start <= end) {
		long long int mid = (start + end) / 2;
		long long int fx = (mid * (mid + 1) * (2 * mid + 1)) / 6;
		if (n == fx) {
			return mid;
		}
		else if (n > fx) {
			res = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return res;
}

int main() {
	long long int n;
	cin >> n;

	cout << killinSpree(n);

	return 0;
}