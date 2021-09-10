#include <bits/stdc++.h>

using namespace std;

inline auto solve () {
	string s; cin >> s;
	size_t L = s.find('a');
	size_t n = s.length(), R = L;
    bool yes = true;
    if (L == string::npos) {
        cout << "NO" << endl;
        return;
    }
    for (size_t i = 1; i < n; i++) {
        size_t pos = s.find(char('a' + i));
        if (pos == string::npos || (pos != L - 1 && pos != R + 1)) {
            yes = false;
            break;
        } else {
            L = min(L, pos);
            R = max(R, pos);
        }
    }
    cout << (yes ? "YES" : "NO") << endl;
}

int main () {
	int tc = 1; 
	cin >> tc;
	while (tc --> 0)
		solve();
}

