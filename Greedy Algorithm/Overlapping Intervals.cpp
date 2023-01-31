//https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1?page=1&difficulty[]=1&status[]=unsolved&curated[]=1&sortBy=accuracy
//Sorting, Greddy
//Sort the interval based on first 
//store initial interval in two pointers
//keep updating second if interval merges
//If there comes inteval which is not merging push the current pointers in answer and update pointers 
//push remaining pointers after execution

#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
	vector<vector<int>>ans;
	sort(intervals.begin(), intervals.end());
	
	int start = intervals[0][0];
	int end = intervals[0][1];

	for (int i = 0; i < intervals.size(); i++)	{
		int startInter = intervals[i][0];
		int endInter = intervals[i][1];

		if (startInter <= end) {
			end = max(end, endInter);
		}
		else {
			ans.push_back({start, end});
			start = startInter;
			end = endInter;
		}
	}
	ans.push_back({start, end});

	return ans;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>>arr(n, vector<int>(2, 0));

	for (int i = 0; i < n; i++)	{
		cin >> arr[i][0] >> arr[i][1];
	}

	for (auto it : overlappedInterval(arr)) {
		cout << it[0] << " " << it[1] << endl;
	}

	return 0;
}