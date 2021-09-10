#include <bits/stdc++.h>

using namespace std;

inline auto solve () {
	int n,k ;
	cin >> n >> k;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		a.push_back(temp);
	}
	bool dp[k + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= k; i++) {
		for (auto x : a) {
			if (i >= x and !dp[i - x]){
				dp[i] = 1;
			}
		}
	}
	cout << (dp[k] ? "First" : "Second") << endl;
}

int main () {
	int tc = 1; 
	// cin >> tc;
	while (tc --> 0)
		solve();
}

