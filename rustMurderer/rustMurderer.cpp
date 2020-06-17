/*
 * Puzzle Link: https://www.hackerrank.com/challenges/rust-murderer/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *		This problem can be solved using a simple BFS in O(n^2) time
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
#define INF 0x7FFFFFFF
#define INFL 0x7FFFFFFFFFFFFFFF
typedef std::pair<int, int> ipair;
using namespace std;

int main() {
	int testCases; cin >> testCases;
	while (testCases--) {
		int n,  m; cin >> n >> m;
		vector<unordered_set<int>>graph(n+1);
		for (int j = 1 ; j < (int)graph.size(); j++) {
			for (int i = 1; i <= n; i++){
				if (i == j) continue;
				graph[j].insert(i);
			}
		}
		vector<int> bestDist(n+1, INF);
		while (m--){
			int u, v; cin >> u >> v;
			graph[u].erase(v);
			graph[v].erase(u);

		}
		int startVertex; cin >> startVertex;
		unordered_set<int>frontier;
		frontier.insert(startVertex);
		bestDist[startVertex] = 0;
		int i = 0;
		while (frontier.size()){
			i++;
			unordered_set<int> next = frontier;
			frontier.clear();
			for (auto vertex : next){
				for (auto neighbor: graph[vertex]){
					frontier.insert(neighbor);
					if (bestDist[neighbor] == INF)
					bestDist[neighbor] = i;
				}
			}
			for (auto visited : next) {
				graph[visited].clear();
				for (auto &s : graph) {
					s.erase(visited);
				}
				frontier.erase(visited);
			}
		}
		for (int i = 1 ; i <= n; i++){
			if (i == startVertex) continue;
			cout << bestDist[i] << " " ;
		}
		cout << endl;
	}
}
