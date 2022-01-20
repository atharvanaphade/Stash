#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int >> dir = {{-1,0},{0,1},{1,0},{0,-1}};

void input(vector<vector<int> > &lot, int row, int col) {
    for (int i = 0; i < row ;i++) {
        for (int j = 0 ; j < col ; j++) {
            int x;
            cin >> x;

            lot[i][j] = x;
        }
    }
}

int bfs(vector<vector<int> > &lot,int row, int col) {
    queue<pair<pair<int,int>, int>  > q;
    q.push({{0,0},0});

    int min_dis = -1;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dis = q.front().second;

        q.pop();

        if (lot[x][y] == 9) {
            min_dis = dis;
            break;
        }

        lot[x][y] = -1;

        for (auto d : dir) {
            int x_coord = x + d.first;
            int y_coord = y + d.second;

            if (x_coord < 0 || x_coord >= row || y_coord < 0 || y_coord >= col || lot[x_coord][y_coord] == 0 || lot[x_coord][y_coord] == -1) continue;

            q.push({{x_coord,y_coord},dis+1});

        }
    }

    return min_dis;
}


int main() {
    int row,col;
    cin >> row >> col;

    vector<vector<int> > lot(row,vector<int> (col,0));
    input(lot,row,col);

    cout << bfs(lot,row,col);
}