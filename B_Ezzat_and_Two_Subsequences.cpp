#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline auto solve() {
	int n; cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		a.push_back(temp);
	}
	int maxx = a[0];
	ll sum = 0;
	for (auto i : a) {
		if (i > maxx) {
			maxx = i;
		}
		sum += i;
	}
	cout << fixed << setprecision(10);
	cout << 1.0 * (sum - maxx) / (n - 1) + maxx << endl;
}

int main () {
	int tc; cin >> tc;
	while (tc --> 0)
		solve();
}