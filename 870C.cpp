#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> primes;
const int maxn = 16;

void sieve(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
}

inline auto solve () {
	vector<int> ans(maxn, -1);
    ans[0] = 0;
    for (int i = 1; i < maxn; ++i) {
        for (auto j: vector<int>{4, 6, 9}) {
            if (i >= j && ans[i - j] != -1) {
                ans[i] = max(ans[i], ans[i - j] + 1);
            }
        }
    }
 
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        if (n < maxn) {
            cout << ans[n] << '\n';
        } else {
            int t = (n - maxn) / 4 + 1;
            cout << t + ans[n - 4 * t] << '\n';
        }
    }
}

int main () {
	// sieve(100000);
	int tc = 1; 
	// cin >> tc;
	while (tc --> 0)
		solve();
}

