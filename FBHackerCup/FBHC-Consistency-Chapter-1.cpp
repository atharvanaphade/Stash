#include <bits/stdc++.h>

using namespace std;



int main () {
	int tc; cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		string s; cin >> s;
		int aeiou = 0, bcd = 0;
		unordered_map<char, int> q1, q2;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U') {
				q1[s[i]]++;
				aeiou++;
			} else {
				q2[s[i]]++;
				bcd++;
			}
		}
		int maxx = 0, maxx1 = 0, ret = -1, rett = -1;
		for (auto i : q1) {
			if (maxx < i.second) {
				ret = i.first;
				maxx = i.second;
			}
		}
		for (auto i : q2) {
			if (maxx1 < i.second) {
				rett = i.first;
				maxx1 = i.second;
			}
		}
		cout << "Case #" << tt << ": " << min (bcd + 2 * (aeiou - maxx), aeiou + 2 * (bcd - maxx1)) << "\n";
	}
}
