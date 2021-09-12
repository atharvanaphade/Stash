#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		int n; cin >> n;
		string s; cin >> s;
		int ret = 0;
		int gg = 0;
		bool hand = s[0] == 'X' ? 0 : 1;
		if (s[0] == 'F') {
			int gg = 1;
			while (s[gg - 1] == s[gg]) {
				gg++;
			}
			if (s[gg] == 'O') {
				hand = 1;
			} else if (s[gg] == 'X') {
				hand = 0;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == 'F') {
				if (hand and s[i + 1] == 'X') {
					hand = !hand;
					ret++;
				} else if (!hand and s[i + 1] == 'O') {
					hand = !hand;
					ret++;
				}
			} else if (s[i + 1] != 'F' and s[i] != s[i + 1]) {
				hand = !hand;
				ret++;
			}
		}
		cout << "Case #" << i << ": " << ret << "\n";
	}
}