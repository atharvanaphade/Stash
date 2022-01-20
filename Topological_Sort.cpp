#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void solve(int toBeat, vector<vector<int>>& pre) {
		map<int, vector<int>> adj;
		unordered_set<int> vis;
		vector<int> topSort;

		// create adjacency list
		for (auto i : pre) {
			adj[i[0]].push_back(i[1]);
		}

		// traverse each node's prerequisite, till there is no prerequisite.
		stack<int> st; // stack to implement recursion.
		st.push(pre[0][0]);
		while (!st.empty()) {
			int curr = st.top();
			st.pop();
			for (auto k : adj[curr]) {
				if (adj[k].size() == 0 and vis.count(k) == 0) {
					vis.insert(k);
				} else if (vis.count(k) == 0) {
					st.push(k);
				}
			}
			vis.insert(curr);
		}

		vis.size() <= toBeat ? cout << "Yes" : cout << "No";
		cout << "\n";
	}
};

int main () {
	Solution s;
	s.solve();
}