#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m, k;
	cin >> n >> m >> k;
	int ret = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int l = 0;
	while (l <= k) {
		vector<int> tmpp = v;
		int rett = 0;
		for (int i = 0; i < n; i++) {
            if (tmpp[i] % m == 0) {
				rett++;
			} else if ((tmpp[i] + l) % m == 0) {
                rett++;
            }
		}
		ret = max(ret, rett);
		l++;
	}
	cout << ret << endl;
}