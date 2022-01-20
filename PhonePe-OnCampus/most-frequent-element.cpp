// You are given an integer array nums and an integer k.
// In one operation, you can choose an index of nums 
// and increment the element at that index by 1.
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main () {
	int n; cin >> n;
	vector<int> nums;
	int k; cin >> k;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		nums.push_back(temp);
	}

	sort(nums.begin(), nums.end());
	ll sum = 0;
	int ret = 1, st = 0, prev = 0;

	for (int i = 0; i < n; i++) {
		sum += (ll)(i - st) * (nums[i] - prev);

		if (sum > k) {
			ret = max(ret, i - st);

			while (st <= i and sum > (ll)k) {
				sum -= nums[i] - nums[st++];
			}
		}
		
		prev = nums[i];
	}

	ret = max(ret, (int)n - st);

	cout << ret << "/n";
}