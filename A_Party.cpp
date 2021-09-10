#include <bits/stdc++.h>

using namespace std;

void dfs (int node, vector<int> a[], int n, int vis[], int &count, int &temp) {
    vis[node] = 1;
    temp++;
    if (count < temp) count = temp;
    for (auto i : a[node]) {
        dfs (i, a, n, vis, count, temp);
        temp--;
    }
}

int main () {
    int n; cin >> n;
    vector<int> v[n + 1];
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        if (temp != -1)
            v[temp].push_back(i);
    }
    int vis[n + 1];
    memset(vis, 0, sizeof(vis));
    int count = 0, temp = 0;
    for (int i = 1; i <= n; i++) {
        temp = 0;
        if (!vis[i]) {
            dfs (i, v, n, vis, count, temp);
        }
    }
    cout << count << endl;
}