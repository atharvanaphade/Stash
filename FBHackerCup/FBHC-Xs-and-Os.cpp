#include <bits/stdc++.h>

using namespace std;

int main () {
	int tc; cin >> tc;
	for (int tt = 1; tt <= tc; tt++) {
		int count; cin >> count;
		char arr[count][count];
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				cin >> arr[i][j];
			}
		}

		int ret = INT_MAX; 
		int count1 = 0;
		map<int, int> mp;
		int qq;
		for (int i = 0; i < count; i++) {
			int x = 0;
			bool fl = 0;
			for (int j = 0; j < count; j++) {
				if (arr[i][j] == 'O') {
					fl = 1;
					break;
				} else if (arr[i][j] == '.') {
					x++;
					qq = j;
				}
			}
			if (!fl and ret > x) {
				ret = x;
				count1 = 1;
				if (ret == 1)
					mp[qq]++;
			} else if (!fl and ret == x) {
				count1++;
				if (ret == 1) {
					mp[qq]++;
				}
			}
		}
		for (int i = 0; i < count; i++) {
			if (!mp[i]) {
				int x = 0;
				bool fl = 0;
				for (int j = 0; j < count; j++) {
					if (arr[j][i] == 'O') {
						fl = 1;
						break;
					} else if (arr[j][i] == '.')
						x++;
				}
				if (!fl and ret > x) {
					ret = x;
					count1 = 1;
				} else if (!fl and ret == x) {
					count1++;
				}
			}
		}
		if (ret == INT_MAX) {
			cout << "Case #" << tt << ": Impossible\n";
		} else {
			cout << "Case #" << tt << ": " << ret << " " << count1 << "\n";
		}
	}
}