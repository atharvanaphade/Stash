#include <bits/stdc++.h>

using namespace std;

vector<int> v[300000];

int main () {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x; cin >> x;
        v[x].push_back(i + 2);
    }
        bool f = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i].size() == 0) continue;
            count = 0;
            for (int j = 0; j < v[i].size(); j++) {
                if (!v[v[i][j]].size()) {
                    count++;
                }
            }
            if (count < 3) {
                f = 1;
            }
        }
        if (f) cout << "No" << endl;
        else cout << "Yes" << endl;
    
}