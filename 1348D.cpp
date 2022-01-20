#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
	int tc; cin >> tc;
	while (tc --> 0) {
		int n; cin >> n;
		vector<ll> two;
		int i = 1;
		while (i <= n) {
			two.push_back(i);
			n -= i;
			i *= 2;
		}
		if (n == 0) {
			cout << two.size() << "\n";
			for (auto j : two) {
				cout << j << " ";
			}
			cout << "\n";
		} else {
			two.push_back(n - i);
			sort(two.begin(), two.end());
			cout << two.size() << "\n";
			for (auto j : two) {
				cout << j << " ";
			}
			cout << "\n";
		}
	}
}