#include <bits/stdc++.h>

using namespace std;

inline auto solve () {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int size[3] = {a, b, c};
	int dp[n + 1];
	memset (dp, -1000000, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		if (i >= size[0]) {
			dp[i] = max (dp[i], dp[i - size[0]] + 1);
		} if (i >= size[1]) {
			dp[i] = max (dp[i], dp[i - size[1]] + 1);
		} if (i >= size[2]) {
			dp[i] = max (dp[i], dp[i - size[2]] + 1);
		}
	}
	cout << dp[n] << "\n";
}

int main () {
	// int tc; cin >> tc;
	int tc = 1;
	while (tc --> 0)
		solve ();
}