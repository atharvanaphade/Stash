#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main () {
	int n; cin >> n;
	int c[1005];
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int ret = 0, open = 0;
	for (int i = 1; i <= n; i += 2) {
		int toBal = c[i], minn = c[i];
		for (int j = i + 1; j <= n; j++) {
			if (j % 2 == 0) {
				if (c[j] + minn >= toBal) {
					if (j == i + 1) {
						ret--;
					}
					ret += min (minn + 1, c[j] + 1 - toBal + minn);
				}
				toBal -= c[j];
				minn = min (minn, toBal);
			} else {
				toBal += c[j];
			}
			if (toBal < 0) {
				break;
			}
		}
	}
	cout << ret << endl;
}