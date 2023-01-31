#include <iostream>
#include <string>
using namespace std;

void permutation(string str, int start, int end){
	if(start == end){
		cout<<str<<endl;
		return;
	}
	
	for(int i=start;i<=end;i++){
		swap(str[start], str[i]);
		permutation(str,start+1,end);
		swap(str[start], str[i]);
	}
}

int main(){
	string str="abc";
	int l=0;
	int r=str.length()-1;
		
	permutation(str,l,r);
	
	return 0;
}
