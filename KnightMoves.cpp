#include <bits/stdc++.h>

using namespace std;

struct cell {
	int x, y;
	int dist;
	cell () {}
	cell(int x, int y, int dist)
	        : x(x), y(y), dist(dist)
	    {
    }
};

bool isInside(int x, int y, int N) {
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minMoves (int n, int startRow, int startCol, int endRow, int endCol) {
	int start[] = {startRow, startCol};
	int end[] = {endRow, endCol};

	int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	queue<cell> q;

	q.push(cell(start[0], start[1], 0));

	cell t;
	int x, y;
	bool vis[n + 1][n + 1];
	memset(vis, 0, sizeof(vis));

	vis[start[0]][start[1]] = 1;

	while (!q.empty()) {
		t = q.front();
		q.pop();

		if (t.x == end[0] and t.y == end[1]) {
			return t.dist;
		}

		for (int i = 0; i < n; i++) {
			
		}
	}
}