/*
 * Puzzle Link: https://www.hackerrank.com/challenges/cut-the-tree/problem
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
int dfs(int loc, set<int>&visited, unordered_map<int, vector<int>>&adj, vector<int>&weights){
	if (visited.find(loc) != visited.end()) return 0;
	visited.insert(loc);
	int m = 0;
	for (auto neighbor : adj[loc]){
		m += dfs(neighbor, visited, adj, weights);
	}
	return m + weights[loc];
}
int main() {
	int n; cin >> n;
	vector<int> v(1,0);
	unordered_map<int , vector<int>> adj;
	vector<pair<int,int>> edges;
	int i =1;
	while (i <= n){
		int a ; cin >> a;
		v.push_back(a);
		adj[i] = {};
		i++;
	}
	int min = 100000000;
	for (int i = 1; i < n; i++ ){
		int a , b; cin >> a >> b;
		edges.push_back({a,b});
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int total = 0;
	for (auto i : v) total += i;
	for (auto edge: edges){
		set<int>visited = {edge.first};
		int a = dfs(edge.second, visited, adj, v);
		min = std::min(total - a, min);
	}
	cout << min << endl;
}
