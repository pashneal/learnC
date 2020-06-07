/*
 * Puzzle Link: https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <unordered_map>
#include <math.h>

using namespace std;
void dfs (int x, int y, vector<vector<int>>&grid, int & count){
	if (!grid[y][x]) return;
	count++;
	grid[y][x] = 0;

	dfs(x - 1, y , grid, count); 
	dfs(x + 1, y , grid, count); 
	dfs(x , y - 1 , grid, count); 
	dfs(x , y + 1 , grid, count);
	dfs(x - 1, y - 1, grid, count);
	dfs(x - 1, y + 1, grid, count);
	dfs(x + 1, y - 1, grid, count);
	dfs(x + 1, y + 1, grid, count);
}
int main() {
	int n,m; cin >> n >> m;
	vector<vector<int>>grid(n);
	for (auto& v : grid){
		v.resize(m+2, 0);
		for (int i = 1 ; i <= m ; i++){
			cin >> v[i];
		}
	}
	//pad the top and bottom left and right  with 0s to prevent boundary checking
	vector<int>v(m+2, 0);
	grid.push_back(v);
	grid.insert(grid.begin(), v);
	int best = 0;
	for (auto y = 1; y <= n; y++){
		for (auto x = 1; x <= m; x++){
			int count = 0;
			dfs(x,y,grid,count);
			best = std::max(best, count);
		}
	}
	cout << best;
}
