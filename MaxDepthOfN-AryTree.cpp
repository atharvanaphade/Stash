#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node () {
	}

	Node (int _val) {
		this->val = _val;
	}
};

int Help (Node* root) {
	if (!root) return 0;
	int maxx = 0;
	for (auto i : root->children) {
		maxx = max (maxx, Help(i));
	}
	return maxx + 1;
}

void Solution (Node* root) {
	cout << Help (root) << "\n";
}

int main () {
	Node* root;
	Solution (root);
}