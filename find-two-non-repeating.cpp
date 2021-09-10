#include <bits/stdc++.h>

using namespace std;

int main () {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int ret = a[0];
	for (int i = 1; i < n; i++) {
		ret ^= a[i];
	}
	int p = 0, q = a[0];
	int last_bit = ret & ~(ret - 1);
	for (int i = 1; i < n; i++) {
		if (a[i] & last_bit) p ^= a[i];
	}
	cout << (ret ^ p) << " " << p << endl;
}