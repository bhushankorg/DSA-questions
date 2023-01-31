//josephus problem using recursion (counting starts from position zero)
#include <iostream>
using namespace std;

int jos(int n, int d){
	if(n==1)
	return 0;
	
	return (jos(n-1,d)+d)%n;
}

int main(){
	int n=40,k=7;
	cout<<jos(n,k);
	
	return 0;
}
