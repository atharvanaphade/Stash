#include <bits/stdc++.h>

using namespace std;

void Permutations (int idx, vector<int>& nums, vector<vector<int>>& ret) {
	if (idx == nums.size()) {
		ret.push_back(nums);
		return;
	}
	for (int i = idx; i < nums.size(); i++) {
		swap(nums[i], nums[idx]);
		Permutations(idx + 1, nums, ret);
		swap(nums[i], nums[idx]);
	}
}

int main () {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<vector<int>> ret;
	Permutations(0, arr, ret);
	for (auto i : ret) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
}