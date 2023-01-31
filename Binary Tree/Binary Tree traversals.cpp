//input = 2 4 7 -1 -1 -1 1 8 -1 -1 3 -1 -1 
#include <bits/stdc++.h>
using namespace std;
#define INT_MIN_VALUE -2147483648
#define INT_MAX_VALUE 2147483647

class Node {
public:
	int data;
	Node *right, *left;

	Node(int x) {
		data = x;
		left = right = NULL;
	}
};

Node* createTree() {
	int data;
	cout << "Enter Data :" << endl;
	cin >> data;

	if (data == -1) return NULL;

	Node* root = new Node(data);

	cout << "Enter left for " << data << endl;
	root->left = createTree();

	cout << "Enter right for " << data << endl;
	root->right = createTree();

	return root;
}

void inOrder(Node* root) {
	if (root == NULL) return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);

	return;
}

void preOrder(Node* root) {
	if (root == NULL) return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);

	return;
}

void postOrder(Node* root) {
	if (root == NULL) return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";

	return;
}

int main() {
	Node* root = createTree();

	cout << "\nInorder traversal :" << endl;
	inOrder(root);

	cout << "\nPreorder traversal :" << endl;
	preOrder(root);

	cout << "\nPostorder traversal :" << endl;
	postOrder(root);

	return 0;
}