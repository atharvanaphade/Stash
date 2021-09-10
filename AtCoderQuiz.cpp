#include <bits/stdc++.h>

using namespace std;

vector<string> ans = { "ABC", "ARC", "AGC", "AHC" };

int main () {
	vector<string> arr;
	for (int i = 0; i < 3; i++) {
		string tmp; cin >> tmp;
		arr.push_back(tmp);
	}
	bool isPresent[4];
	for (auto r : isPresent) {
		r = 0;
	}
	for (int i = 0; i < 4; i++) {
		for (auto j : arr) {
			if (j == ans[i]) {
				isPresent[i] = 1;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (!isPresent[i]) {
			cout << ans[i] << "\n";
			return 0;
		}
	}
}