//Top View of Binary Tree
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

vector<int> topView(Node* root) {
	queue<pair<int, Node*>>q;
	map<int, int>mp;
	q.push({0, root});

	while (!q.empty()) {
		Node* tmp = q.front().second;
		int hd = q.front().first;
		q.pop();

		if (mp.find(hd) == mp.end()) {
			mp[hd] = tmp->data;
		}

		if (tmp->left) {
			q.push({hd - 1, tmp->left});
		}
		if (tmp->right) {
			q.push({hd + 1, tmp->right});
		}
	}
	vector<int>ans;
	for (auto i : mp) {
		ans.push_back(i.second);
	}

	return ans;
}

int main() {
	Node* root = createTree();

	vector<int>ans =  topView(root);

	for (int i = 0; i < ans.size(); ++i)	{
		cout << ans[i] << " ";
	}

	return 0;
}