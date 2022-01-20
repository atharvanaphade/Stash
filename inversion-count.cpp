#include <bits/stdc++.h>

using namespace std;

inline auto solve() {
	int n; cin >> n;
	int ret = 0;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0 ; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (i < j and arr[i] > arr[j]) {
				ret++;
			}
		}
		cout << arr[i] << " ";
	}

	cout << ret << "\n";
}

int main() {
	int tc; cin >> tc;
	while (tc --> 0) {
		string c; cin >> c;
		solve();
	}
}