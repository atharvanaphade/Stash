#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc; cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		int n; cin >> n;
		string s; cin >> s;
		auto counttt = [&](string& s) {
			int n = s.size(), countt = -1;
			char recent;
			for (int i = 0; i < n; i++) {
				if (s[i] == 'O' or s[i] == 'X') {
					if (recent != s[i]) {
						recent = s[i];
						countt += 1;
					}
				}
			}
			if (countt == -1) {
				countt = 0;
			}
			return countt;
		};
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				string str = "";
				for (int k = i; k < j + 1; k++) {
					str += s[k];
				}
				sum += counttt(str);
			}
		}
		cout << "Case #" << tt << ": " << sum << "\n";
	}
}