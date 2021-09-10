#include <bits/stdc++.h>
#define inputvec(v, n) for (int i = 0; i < n; i++) {int temp; cin >> temp; v.push_back(temp);}

using namespace std;

inline auto solve () {
	int n; cin >> n;
	vector<int> ret;
	vector<pair<int, int>> su(n);
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		su[i].first = temp;
	}
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		su[i].second = temp;
	}
	sort (su.begin(), su.end());
	int k = 1, strength = 0;
	while (k <= n) {
		
	}
}

int main () {
	int tc; cin >> tc;
	while (tc --> 0)
		solve ();
}