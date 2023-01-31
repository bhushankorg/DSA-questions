#include <bits/stdc++.h>
#define N 4
using namespace std;

bool isSafe(int board[N][N], int row, int col){
	int j;
	//checking left horizontal attack
	for(int i=0;i<col;i++){
		if(board[row][i] == 1)
		return false;
	}
	//checking top vertical attack
	for(int i=0;i<row;i++){
		if(board[i][col] == 1)
		return false;
	}
	//checking left top diagonal attack
	for(int i=row,  j=col ; i>=0&&j>=0 ; i--,j--){
		if(board[i][j] == 1)
		return false;
	}
	//checking right top diagonal attack
	for(int i=row,  j=col ; i>=0&&j<N ; i--,j++){
		if(board[i][j] == 1)
		return false;
	}
	
	return true;
}

bool nqueen(int board[N][N], int row, int n){
	if(row==n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	
	for(int col=0;col<n;col++){
		if(isSafe(board,row,col)){
			board[row][col]=1;
			
			if(nqueen(board,row+1,n))
		 	return true;
					
			board[row][col]=0;//backtracking step
		}
	}
	return false;
}


int main(){
	int n=4;
	int board[4][4]={0};
	
	if(nqueen(board,0,n)){
		cout<<"\nis a possible way";
	}
	else
	cout<<"not possible";
	
	return 0;
}
