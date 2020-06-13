/*
 * Puzzle Link: https://www.hackerrank.com/challenges/synchronous-shopping/problem
 * Puzzle Difficulty: Medium 
 *  (But it should really be a bit higher)
 *
 * Initial Thoughts:
 *		Not sure if an effecient algo exists in terms the input space (n and k)
 *		but since k is small there is a feasible brute forced implementation of dijkstra
 *		in O(n*2^k + 2^(2k)) time and O(n* 2^k) space
 *
 */
#include <vector>
#include <bitset>
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
typedef std::tuple<int, int, int> ints;
typedef std::pair<int, int> ipair;
using namespace std;
int main() {
	//priority queue holds {bitmask, weight at u -> v, v}
	//adj holds {weight, neighbor}
	//fish holds {bitmask} where every set bit is a fish
	priority_queue<ints, vector<ints>, greater<ints>> pq;
	int n, m , k; cin >> n >> m >> k;
	vector<vector<long>>bestDist(n + 1, vector<long>(1 << k , INFL));
	vector<vector<ipair>>adj(n + 1);
	vector<int>fish(n+1, 0);

	for (int i = 1; i <= n ; i++){
		int numFish; cin >> numFish;
		int bitmask = 0;
		//bit mask where every bit represents a fish
		//fish n = 2^(n-1)
		while (numFish--){
			int a; cin >> a;
			bitmask |= 1 << (a-1);	
		}
		fish[i] = bitmask;
	}

	//set bidirectional edges 
	while (m--){
		int u, v, weight; cin >> u >> v >> weight;
		adj[u].push_back({weight,v});
		adj[v].push_back({weight,u});
	}

	//initialize bestDist and prority_q to the source node
	bestDist[1][fish[1]] = 0;
	pq.push({fish[1], 0, 1});

	//run dijkstra to find shortest paths
	while (!pq.empty()) {
		int fishSoFar = std::get<0>(pq.top());
		int vertex = std::get<2>(pq.top());
		pq.pop();
		for (auto& edge : adj[vertex]){
			int weight = edge.first;
			int neighbor = edge.second;
			long weightToNeighbor = weight + bestDist[vertex][fishSoFar];
			//get fish that is present at this neighbor
			//and combine it with the prev fish
			int newFishSoFar = fishSoFar;
			newFishSoFar |= fish[neighbor];
			//reduce to the smallest distance
			if (bestDist[neighbor][newFishSoFar] > weightToNeighbor){
				bestDist[neighbor][newFishSoFar] = weightToNeighbor;
				pq.push({newFishSoFar, weightToNeighbor, neighbor});
			}
		}
	}

	// since there are two different actors, check all pairs to see what
	// combination of best paths would result in both actors arriving to the destination
	// since both paths occur in parallel, we only need to count the path that takes the most
	// amount of time
	int allFish = (1 << k) - 1;
	long bestDistanceToEnd = INFL;
	for (int i = 0; i <= allFish; i++){
		for (int j = i + 1; j <= allFish; j++){
			if ((i | j ) == allFish && bestDist[n][i] != INFL && bestDist[n][j] != INFL) {
				long longer = std::max(bestDist[n][i], bestDist[n][j]);
				bestDistanceToEnd = min(bestDistanceToEnd, longer);
			}
		}
	}
	//assuming that the actors traveled together the entire time
	bestDistanceToEnd = min(bestDistanceToEnd, bestDist[n][allFish]);
	cout << bestDistanceToEnd;
}
