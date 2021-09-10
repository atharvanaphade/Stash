#include <bits/stdc++.h>

using namespace std;

inline auto solve () {
	int n, k; cin >> n >> k;
	vector<pair<int, int>> a;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	int ret = 0;
	for (int i = 1; i < a.size(); i++) {
		if (a[i - 1].second + 1 != a[i].second)
			ret++;
	}
	cout << (ret <= k ? "YES\n" : "NO\n");
}

int main () {
	int tc; cin >> tc;
	while (tc --> 0)
		solve ();
}