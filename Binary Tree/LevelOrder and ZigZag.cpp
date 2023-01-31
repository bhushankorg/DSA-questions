//1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1 
//LevelOrder and ZigZag
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

vector<int> levelOrder(Node* root) {
	queue<Node*>q;
	vector<int>traversal;
	q.push(root);
	while (!q.empty()) {
		Node* tmp = q.front();
		q.pop();
		traversal.push_back(tmp->data);
		if (tmp->left) {
			q.push(tmp->left);
		}
		if (tmp->right) {
			q.push(tmp->right);
		}
	}
	return traversal;
}

vector<vector<int>> zigzag(Node* root) {
	queue<Node*>q;
	vector<vector<int>>traversal;
	q.push(root);

	bool isLtoR = true;

	while (!q.empty()) {
		int n = q.size();
		vector<int>temp(n);
		for (int i = 0; i < n; i++)	{
			Node* tmp = q.front();
			q.pop();

			int index = (isLtoR) ? i : (n - 1 - i);
			temp[index] = tmp->data;

			if (tmp->left) {
				q.push(tmp->left);
			}
			if (tmp->right) {
				q.push(tmp->right);
			}
		}
		isLtoR = !isLtoR;
		traversal.push_back(temp);
	}
	return traversal;
}

int main() {
	Node* root = createTree();

	cout << "LevelOrder Traversal : ";
	for (int i : levelOrder(root)) {
		cout << i << " ";
	}

	cout << "ZigZag Traversal : ";
	vector<vector<int>> ans = zigzag(root);

	for (int i = 0; i < ans.size(); i++)	{
		for (int j = 0; j < ans[i].size(); j++)	{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}