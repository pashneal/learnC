/*
 * Puzzle Link: https://www.hackerrank.com/challenges/torque-and-development/problem
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
void dfs(unordered_map<int , vector<int>>& adj, set<int>&visited, int i) {
	if (visited.find(i) != visited.end()) return;
	visited.insert(i);
	for (int neighbor : adj[i]){
		dfs(adj, visited, neighbor);
	}
}

int main() {
	int q; cin >> q;
	while (q--){
		int n,m; cin >> n >> m;
		int lib, road; cin >> lib >> road;
		unordered_map<int,vector<int>>adj;
		while(n--){
			adj[n + 1] = {};
		}
		while(m--){
			int u, v; cin >> u >> v;
			adj[u].push_back(v);
		}
		n = adj.size(); 
		set<int>visited;
		set<int>old;
		int total = 0;
		for (int i = 1; i <= n; i++){ 
			dfs(adj, visited, i);
			if (visited.size() != old.size()) total += 1;
			old = visited;
		}
		if (lib <= road) {
			cout << n*lib << endl;
		} else {
			cout << (total)*lib + (n-total)*road << endl;
		}
	}
}
