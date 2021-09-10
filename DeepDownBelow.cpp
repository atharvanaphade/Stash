#include <bits/stdc++.h>

using namespace std;

inline auto solve () {
	int n, x, k; cin >> n;
	vector<int> a[n];
	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> x;
			a[i].push_back(x);
		}
	}
	vector<pair<int, int>> b(n);
	for (int i = 0; i < n; i++) {
		b[i].first = INT_MIN;
		b[i].second = i;
		for (int j = 0; j < a[i].size(); j++) {
			b[i].first = max (b[i].first, a[i][j] - j);
		}
	}
	sort (b.begin(), b.end());
	int p = INT_MIN;
	int s = 0;
	for (int i = 0; i < n; i++) {
		p = max	(p, b[i].first - s);
		s += a[b[i].second].size();
	}
	cout << p + 1 << endl;
}

int main () {
	int tc; cin >> tc;
	while (tc --> 0)
		solve ();
}