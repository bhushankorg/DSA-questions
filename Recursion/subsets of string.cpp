#include <iostream>
#include <string>
using namespace std;

void subset(string str, int count, string current){
	if(count == str.length()){
		cout<<"***"<<current<<"***"<<endl;
		return; 
	}
	
	subset(str,count+1,current+str[count]);
	subset(str,count+1,current);
}

int main(){
	string str="abc";
	int i=0;
	string curr="";
	
	subset(str,i,curr);
	
	return 0;
}
