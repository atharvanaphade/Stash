#include <bits/stdc++.h>

using namespace std;

void Solution (vector<pair<int, int>>& arr, int n) {
	auto cmp = [&](pair<int, int> a, pair<int, int> b) {
		return (a.first < b.first);
	};
	sort(arr.begin(), arr.end(), cmp);
	stack<pair<int, int>> s;
	s.push(arr[0]);
	for (int i = 1; i < n; i++) {
		auto tt = s.top();
		if (tt.second < arr[i].first) {
			s.push(arr[i]);
		} else if (tt.second < arr[i].second) {
			tt.second = arr[i].second;
			s.pop();
			s.push(tt);
		}
	}
	while (!s.empty()) {
		auto curr = s.top();
		s.pop();
		cout << curr.first << " " << curr.second << "\n";
	}
	return;
}

int main () {
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int x; int y;
		cin >> x >> y;
		a[i] = { x, y };
	}
	Solution(a, n);
}