//josephus problem (counting starts from position 1 not zero)
#include <iostream>
#include <vector>
using namespace std;

int josephus(vector<int>arr, int k){
	int index=0;
	while(arr.size() != 1){
		index = (index+k) % arr.size();
		arr.erase(arr.begin()+index);//erasing the index with value prev.i+(d-1) modulo size
	}
	return arr[0];
}

int main(){
	int n=40,d=7;
	vector<int>nums;
	
	for(int i=1;i<=n;i++)
	nums.push_back(i);
	
	cout<<josephus(nums,d-1);
	
	return 0;
}
