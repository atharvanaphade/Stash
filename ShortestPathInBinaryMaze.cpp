#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int mat[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	auto isValid = [&](int r, int c) { // Check if the square is valid to check neighbours.
		return (r >= 0) and (r < n) and (c >= 0) and (r < m);
	};
	bool vis[n][m];
	int dist[n][m]; // Distance to the source node, space can be optimized by using struct.
	dist[0][0] = 0;
	memset(vis, 0, sizeof(vis));
	vis[0][0] = 1;
	queue<pair<int, int>> q; // BFS Queue
	q.push({ 0, 0 }); 
	int rowNum[] = { -1, 0, 0, 1 }; // Array to visit neighbours
	int colNum[] = { 0, -1, 1, 0 }; // Array to visit neighbours
	while (!q.empty()) { // BFS
		auto curr = q.front();
		q.pop();
		if (curr.first == x and curr.second == y) {
			cout << dist[curr.first][curr.second];
			return 0;
		}
		for (int i = 0; i < 4; i++) { // Visit neighbours
			int r = curr.first + rowNum[i]; // Neighbours
			int c = curr.second + colNum[i]; // Neighbours

			if (isValid(r, c) and mat[r][c] and !vis[r][c]) {
				vis[r][c] = 1;
				q.push({ r, c });
				dist[r][c] = dist[curr.first][curr.second] + 1;
			}
		}
	}
	cout << "Unreachable" << "\n";
}