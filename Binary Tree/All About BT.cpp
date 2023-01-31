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
	cout << "Enter data :" << endl;
	int data;
	cin >> data;

	if (data == -1) return NULL;

	Node *root = new Node(data);

	cout << "Enter left for " << data;
	root->left = createTree();

	cout << "Enter right for " << data;
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

int heightOfBT(Node* root) {
	if (root == NULL) return 0;

	return max(heightOfBT(root->left), heightOfBT(root->right)) + 1;
}

int sizeOfBT(Node* root) {
	if (root == NULL) return 0;

	return (sizeOfBT(root->left) + sizeOfBT(root->right) + 1);
}

int maxOfBT(Node* root) {
	if (root == NULL) return INT_MIN_VALUE;

	return max(root->data, max(maxOfBT(root->right), maxOfBT(root->left)));
}

int minOfBT(Node* root) {
	if (root == NULL) return INT_MAX_VALUE;

	return min(root->data, min(minOfBT(root->right), minOfBT(root->left)));
}

int main() {
	Node* root = createTree();

	cout << "\nInOrder Traversal :" << endl;
	inOrder(root);

	cout << "\nPreOrder Traversal :" << endl;
	preOrder(root);

	cout << "\nPostOrder Traversal :" << endl;
	postOrder(root);

	cout << "\nHeight of BT : " << heightOfBT(root);

	cout << "Size of BT : " << sizeOfBT(root) << endl;

	cout << "Max NodeVal of BT : " << maxOfBT(root) << endl;

	cout << "Min NodeVal of BT : " << minOfBT(root) << endl;

	return 0;
}