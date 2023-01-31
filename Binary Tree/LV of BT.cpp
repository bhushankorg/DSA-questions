//Left View of Binary Tree
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
	cin >> data;

	if (data == -1) return NULL;

	Node* root = new Node(data);

	root->left = createTree();
	root->right = createTree();

	return root;
}

void printLeftView(map<int, Node*>&mp, Node* root, int level) {
	if (root == NULL) return;

	if (mp.find(level) == mp.end()) {
		mp[level] = NULL;
	}

	if (mp[level] == NULL) {
		mp[level] = root;
	}

	printLeftView(mp, root->left, level + 1);
	printLeftView(mp, root->right, level + 1);

	return;
}

int main() {
	Node* root = createTree();

	map<int, Node*>mp;

	printLeftView(mp, root, 0);

	for (int i = 0; i < mp.size(); ++i)	{
		Node* tmp = mp[i];
		cout << tmp->data << " ";
	}

	return 0;
}