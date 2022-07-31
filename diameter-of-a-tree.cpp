#include <bits/stdc++.h>

#define MAX 200000

using namespace std;

vector<int> adj[MAX];
vector<int> distances;

int far, dist;

void recur(int gg, int pp, int level) {
	if (level > dist) {
		far = gg;
		dist = level;
	}
	for (auto nn : adj[gg]) {
		if (nn != pp)
			recur(nn, gg, level + 1);
	}
}

int solve() {
	far = -1, dist = 0;
	recur(1, -1, 0);
	int end1 = far;
	// cout << end1 << endl;
	far = -1, dist = 0;
	recur(end1, -1, 0);
	// cout << far << endl;
	return dist;
}

int main () {
	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	cout << solve() << endl;
}