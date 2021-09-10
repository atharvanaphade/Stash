#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc; cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		string s; cin >> s;
		int e; cin >> e;
		unordered_map<char, vector<char> > mp;
		unordered_map<char, int> nodes;
		unordered_set<char> tmp;
		for (int i = 0; i < e; i++) {
			string temp; cin >> temp;
			mp[temp[0]].push_back(temp[1]);
			tmp.insert(temp[0]);
			tmp.insert(temp[1]);
		}
		for (char i : s) {
			tmp.insert(i);
		}
		int counter = 0;
		for (char i : tmp) {
			nodes[i] = counter++;
		}
		vector<vector<int>> gg(tmp.size(), vector<int>(tmp.size(), INT_MAX));
		for (int i = 0; i < tmp.size(); i++) gg[i][i] = 0;
		for (auto i : mp) {
			for (auto j : i.second) {
				gg[nodes[i.first]][nodes[j]] = 1;
			}
		}
		for (int k = 0; k < tmp.size(); k++) {
			for (int i = 0; i < tmp.size(); i++) {
				for (int j = 0; j < tmp.size(); j++) {
					if (gg[i][j] > gg[i][k] + gg[k][j] and (gg[k][j] != INT_MAX and gg[i][k] != INT_MAX)) {
						gg[i][j] = gg[i][k] + gg[k][j];
					}
				}
			}
		}
		int ret = INT_MAX;
		for (char i : tmp) {
			int count = 0;
			bool dist = 0;
			for (char c : s) {
				int distt = gg[nodes[c]][nodes[i]];
				if (distt == INT_MAX) {
					dist = 1;
					break;
				}
				count += distt;
			}
			if (dist)
				continue;
			ret = min(ret, count);
		}
		cout << "Case #" << tt << ": ";
		if (ret == INT_MAX) cout << -1 << "\n";
		else cout << ret << "\n";
	}
}