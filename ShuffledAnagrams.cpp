#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		string s; cin >> s;
		string temp = s;
		next_permutation(s.begin(), s.end());
		if (s != temp) {
			cout << "Case #" << t << ": " << s <<"\n";
		} else {
			cout << "Case #" << t << ": " << "IMPOSSIBLE\n";
		}
	}
}