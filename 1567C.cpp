#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc; cin >> tc;
	while (tc --> 0) {
		int a = 0, b = 0;
		int n; cin >> n;
		int pp = 1;
		while (n) {
			a = a + pp * (n % 10);
			n /= 10;
			b = b + pp * (n % 10);
			n /= 10;
			pp *= 10;
		}
		cout << (a + 1) * (b + 1) - 2 << "\n";
	}
}