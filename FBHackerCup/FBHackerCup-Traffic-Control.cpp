#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc; cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		int length = n + m - 1;
		if (length > a or length > b) {
			cout << "Case #" << tt << ": Impossible\n";
			continue;
		}
		printf("Case #%d: Possible\n", tt);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 and j == 0) {
					cout << a - length + 1 << " ";
				} else if (i == 0 and j == m - 1) {
					cout << b - length + 1 << " ";
				} else {
					cout << 1 << " ";
				}
			}
			cout << "\n";
		}
	}
}