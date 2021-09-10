#include <bits/stdc++.h>

using namespace std;

inline auto solve () {
	int n; cin >> n;
	vector<int> h(n);
	for (int& i : h) {
		cin >> i;
	}
	sort(h.begin(), h.end());
	if (n <= 2) {
		sort(h.begin(), h.end());
		for (auto i : h) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	int diff = INT_MAX;
	int id1 = 0, id2 = 1;
	for (int i = 0; i < n - 1; i++) {
		if (h[i + 1] - h[i] < diff) {
			diff = h[i + 1] - h[i];
			id1 = i;
			id2 = i + 1;
		}		
	}
	cout << h[id1] << " ";
	for (int i = id2 + 1; i < n; i++) {
		cout << h[i] << " ";
	}
	for (int i = 0; i < id1; i++) {
		cout << h[i] << " ";
	}
	cout << h[id2] << "\n";
}

int main () {
	int tc; cin >> tc;
	while (tc --> 0)
		solve ();
}