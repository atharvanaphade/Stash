#include <bits/stdc++.h>

using namespace std;

/*
/ Merge two sorted arrays
/ 1. Merge the two arrays, sort it, add to the two arrays (O(NlogN) + O(N))
/ 2. Push the smaller elements in a PriQ, and swap on the longer one, (O(NLogN))
/ 3. Gap Algorithm (O(LogN) and O(1) Space).
*/

void Solution (vector<int>& arr1, vector<int>& arr2) {
	int n = arr1.size(), m = arr2.size();
	
}

int main () {
	vector<int> arr1 = { 1, 4, 7, 8, 10 };
	vector<int> arr2 = { 2, 3, 9 };

	Solution(arr1, arr2);
}