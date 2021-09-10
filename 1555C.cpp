#include <bits/stdc++.h>

using namespace std;

inline auto solve () {
	int m; cin >> m;
	int a[2][m];
	int tot_sum = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			tot_sum += a[i][j];
		}
	}
	int sum1 = 0, sum2 = 0, ret = INT_MAX;
	for (int i = 0; i < m; i++) {
		sum1 += a[0][i];
	}
	for (int i = 0; i < m; i++) {
		sum1 -= a[0][i];
		ret = min (ret, max(sum1, sum2));
		sum2 += a[1][i];
	}
	cout << ret << "\n";
}

int main () {
	int tc; cin >> tc;
	while (tc --> 0)
		solve ();
}
// 1 3 7 9 9
// 3 5 1 1 1