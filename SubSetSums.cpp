#include <bits/stdc++.h>

using namespace std;

// Recursive
void SubsetSums (vector<int>& nums, vector<int>& ret, int l, int r, int sum = 0) {
	if (l > r) {
		ret.push_back(sum);
		return;
	}
	SubsetSums(nums, ret, l + 1, r, sum + nums[l]);
	SubsetSums(nums, ret, l + 1, r, sum);
}

int main () {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> ret;
	SubsetSums(arr, ret, 0, n - 1);
	sort(ret.begin(), ret.end());
	for (auto i : ret) {
		cout << i << " ";
	}
	cout << "\n";
}