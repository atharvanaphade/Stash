#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node () {}

	Node(int _val) {
		this->val = _val;
	}
};

void Solution (Node* root) {
	vector<int> summ;
	summ.push_back(root->val);
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int sum = 0;
		Node* curr = q.front();
		q.pop();
		for (auto i : curr->children) {
			sum += i->val;
			q.push(i);
		}
	}
	int maxx = INT_MIN;
	for (auto i : summ) {
		if (i > maxx) {
			maxx = i;
		}
	}
	cout << maxx << "\n";
}

int main () {
	Node* root;
	Solution (root);
}