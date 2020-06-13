/*
 * Puzzle Link: https://www.hackerrank.com/challenges/maximizing-mission-points/problem?h_r=next-challenge&h_v=zen
 * Puzzle Difficulty: Hard
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
#include <queue>
#define INF 0x7FFFFFFF
#define INFL 0x7FFFFFFFFFFFFFFF
typedef std::pair<long, long> ipair;
typedef std::tuple<int , int, int> itriple;
typedef std::tuple<int, int, int, int> ituple;
using namespace std;

const int LAT = 0;
const int LONG = 1;
const int HEIGHT = 2;
int main() {
	int n, distLat, distLong; cin >> n >> distLat >> distLong;
	vector<itriple>cities(n + 1);
	vector<int> points;
	for (int i = 1; i <= n; i++){
		int lat, lon , height, p; cin >> lat >> lon >> height >> p;
		points[i] = p;
		cities[i] = {lat , lon, height};
	}

	//enumerate edge (u, v) iff height(u) < height(v) and within lat and longitude
	vector<vector<ipair>>adj(n + 1);
	vector<itriple>edges;
	for (int u = 1 ; u <= n; u++){
		for (int v = 1; v <= n; v++){
			if (get<HEIGHT>(cities[u]) < get<HEIGHT>(cities[v])) {
				if ( abs (get<LONG>(cities[u]) - get<LONG>(cities[v])) <= distLong){
					if ( abs (get<LAT>(cities[u]) - get<LAT>(cities[v])) <= distLat){
						//insert weight and vertex
						edges.push_back({u, v, points[u]});
					}
				}
			}
		}
	}

	//for every vertex add an empty edge
	for (auto i = 1; i <= n ; i++){
		edges.push_back({0, i, 0});
	}

	vector<int>bestDist(n + 1, INF);
	//initialize the source node
	bestDist[0] = 0;
	//bellman-ford to find minimum vertex weights
	for (int i = 0; i < n - 1; i++){
		for (auto edge : edges){
			int u = get<0>(edge);
			int v = get<1>(edge);
			int weight = get<2>(edge);
			if (bestDist[u] == INF) continue;

			int pathWeight = weight + bestDist[u];
			if (bestDist[v] < pathWeight) {
				bestDist[v] = pathWeight;
			}
		}
	}
	//reweigh every edge
	for (auto edge: edges){
		int u = get<0>(edge);
		int v = get<1>(edge);
		int weight = get<2>(edge);
		int newWeight = weight + bestDist[u] - bestDist[v];
		adj[u].push_back({newWeight, v});
	}

	long bestPoints[n + 1][n + 1];
	for (auto i = 1; i <= n ; i++){
		for (auto j = 1; j <= n; j++){
			bestPoints[i][j] = INFL;
		}
	}
	//run dijkstra
	for (int i = 1; i <= n; i++){
		//initialize everything
		priority_queue<ipair, vector<ipair>, greater<ipair>>pq;
		pq.push({0, i});
		while(!pq.empty()){
			int u = pq.top().second;
			pq.pop();
			for (auto edge : adj[u]){
				int v = edge.second;
				int weight = edge.first;
				long newWeight = weight + bestPoints[i][u];
				if (bestPoints[i][v] > newWeight){
					bestPoints[i][v] = newWeight;
					pq.push({newWeight, v});
				}
			}
		}
	}
	long ans = 0;
	for (auto i = 1; i <= n ; i++){
		for (int j = 1 ; j<=n ; j++){
			//have to add the final edge as well	
			bestPoints[i][j] += points[j];
			//correct the pathLength and compare
			ans = std::max(bestPoints[i][j] - points[i] + points[j], ans);
		}
	}
	cout << ans;
}
