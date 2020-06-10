/*
 * Puzzle Link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem
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
int dfs( int u,	unordered_map<int, set<int>>&adj, set<int>&visited){

	if (visited.find(u) != visited.end()) return 0;
	visited.insert(u);
	int m = 1;
	for (auto v : adj[u]){
		m += dfs(v, adj , visited);
	}
	return m;
}
int main() {
	int n, k; cin >> n >> k;
	unordered_map<int, set<int>>adj;
	for (int i = 0; i < n; i++) adj[i] = {};
	while (k--) {
		int u, v; cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	long result = 0;
	int t = 0;
	set<int>visited;
	vector<int>rs;
	for (int i = 0; i < n; i++){
		int r = dfs(i, adj, visited);
		if (!r) continue;
		rs.push_back(r);
		t+= r;
	}
	for (auto i: rs){
		t -= i;
		result += i * t;
	}
	cout << result;
}
