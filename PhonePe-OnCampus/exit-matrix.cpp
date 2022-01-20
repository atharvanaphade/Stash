// Count the number of ways to exit a matrix[n][m] from given (sx, sy) in at most k steps.
#include <bits/stdc++.h>

using namespace std;

int noOfMoves;
set<pair<int, int>> vis;

void recur (int x, int y, int m, int n, int k, int currSteps) {
	if (currSteps > k) return;
	if (x <= 0 or y <= 0 or x >= m - 1 or x >= n - 1) {
		vis.insert({ x, y });
		noOfMoves++;
		return;
	}
	vis.insert({ x, y });
	if (vis.find({ x + 1, y }) == vis.end()) {
		recur(x + 1, y, m, n, k, currSteps + 1);
	}
	if (vis.find({ x - 1, y }) == vis.end()) {
		recur(x - 1, y, m, n, k, currSteps + 1);
	}
	if (vis.find({ x, y + 1 }) == vis.end()) {
		recur(x, y + 1, m, n, k, currSteps + 1);
	}
	if (vis.find({ x, y - 1 }) == vis.end()) {
		recur(x, y - 1, m, n, k, currSteps + 1);
	}
}

int main () {
    int m, n, k; cin >> m >> n >> k;
    // For each point check all four recursively.
    int x, y; cin >> x >> y;
    recur(x, y, m, n, k, 0);
    cout << noOfMoves << "\n";

}