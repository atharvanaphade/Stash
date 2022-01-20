#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> arr(n, 0);
	vector<pair<ll, ll>> queries;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < q; i++) {
		ll a, b; cin >> a >> b;
		queries.push_back(make_pair(a, b));
	}
	
	for (int i = 1; i < n; i++) {
		arr[i] += arr[i - 1];
	}
	for (auto i : queries) {
		if (i.first == 1) {
			cout << arr[i.second - 1] << "\n";
		} else {
			cout << arr[i.second - 1] - arr[i.first - 2] << "\n";
		}
	}
}

int main() {
	solve();
}