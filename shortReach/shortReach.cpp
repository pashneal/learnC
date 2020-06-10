/*
 * Puzzle Link: https://www.hackerrank.com/challenges/dijkstrashortreach/problem
 * Puzzle Difficulty: Hard
 *
 * Initial Thoughts:
 *	 requires implementation of specialized graph algorithm
 *	 dijkstra
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
#include <queue>

typedef std::pair<int, int> ipair;
#define INF 0x7FFFFFFF

using namespace std;
int main() {
	int testCases; cin >> testCases;
	while (testCases--) {
		int vertices, edges; cin >> vertices >> edges ;
		vector<set<ipair>>graph(vertices+1);
		int u, v, weight;
		while(edges--){
			scanf("%d %d %d\n", &u, &v, &weight);
			if (u == v) continue;
			graph[u].insert({weight, v});
			graph[v].insert({weight, u});
		}
		int start; cin >> start;

		vector<int> bestDist(vertices+1, INF);
		priority_queue<ipair, vector<ipair> , greater<ipair>> pq;

		bestDist[start] = 0;
		pq.push({0,start});

		while(!pq.empty()) {
			int	vertex = pq.top().second;
			pq.pop();
			for (auto& edge: graph[vertex]){
				int neighbor = edge.second;
				int weight = edge.first;
				int pathWeight = weight + bestDist[vertex];
				if (pathWeight < bestDist[neighbor]) {
					bestDist[neighbor] = pathWeight;
					pq.push({pathWeight, neighbor});
				}
			}
		}

		for (int i = 1; i <= vertices; i++){
			if (i == start) continue;
			if (bestDist[i] == INF) {
				cout << -1 << " ";
				continue;
			}
			cout << bestDist[i] << " "; 
		}
		cout << endl;
	}
}
