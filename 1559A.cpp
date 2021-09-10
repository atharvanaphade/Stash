#include <bits/stdc++.h>

using namespace std;

inline auto solve () {
	int n; cin >> n;
	vector<int> a;
	int ret; cin >> ret;
	for (int i = 0; i < n - 1; i++) {
		int temp; cin >> temp;
		ret &= temp;
	}
	cout << ret << "\n";
}

int main () {
	int tc; cin >> tc;
	while (tc --> 0)
		solve();
}