#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline auto solve () {
    ll n; cin >> n;
    if (n < 6) {
        cout << 15 << endl;
        return;
    }
    if (n % 2 == 0) {
        cout << (ll)(2.5 * n) << endl;
        return;
    } else {
        n++;
        cout << (ll)(2.5 * n) << endl;
        return;
    }
}

int main () {
    int tc; cin >> tc;
    while (tc --> 0)
        solve();
}