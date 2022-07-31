#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& grid, int i, int j, int ret) {
	vector<pair<int,int>> stack;
    stack.push_back(make_pair(i,j));

    while (!stack.empty()){
        pair<int,int> temp = stack.back();
        i = temp.first;
        j = temp.second;
        stack.pop_back();
        
        if (i <0 || i>= grid.size() || j<0 || j >= grid[0].size() ){
            continue;
        }
        
        if (grid[i][j]== 1 ){
        	grid[i][j] = 0;
        	ret++;
            stack.push_back(make_pair(i+1, j));
            stack.push_back(make_pair(i, j+1));
            stack.push_back(make_pair(i-1, j));
            stack.push_back(make_pair(i, j-1));
        }    
    }    
    
    return;
}

int main () {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; i < m; j++) {
			int gg; cin >> gg;
			temp.push_back(gg);
		}
		grid.push_back(temp);
	}

	int ret = 0;
	int count = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == 1) {
				dfs(grid, i, j, ret);
				count++;
			}
		}
	}

	cout << ret << endl;
}
