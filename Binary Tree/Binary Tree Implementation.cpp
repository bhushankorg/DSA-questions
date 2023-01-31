#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

class Node{
public:
	int data;
	Node *right, *left;

	Node(int x){
		data = x;
		left = right = NULL;
	}
};

Node* createTree(){
	int data;
	cout << "Enter Data :" << endl;
	cin >> data;
	
	if(data == -1) return NULL;
	
	Node* root = new Node(data);
	
	cout << "Enter left for " << data << endl;	
	root->left = createTree();
	
	cout << "Enter right for " << data << endl;
	root->right = createTree();
	
	return root;
}

int main() {
	Node* root = createTree();
	
	
	return 0;
}