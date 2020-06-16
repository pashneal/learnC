/*
 * Puzzle Link: https://www.hackerrank.com/challenges/the-quickest-way-up/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	We can do a dynamic programming solution in order to have O(n) time compexity
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

int minMoves(vector<int>&dp, vector<int>&snakes, vector<int>&ladders, vector<int>&visited,
		int loc){
	if (loc >= 100) return 0;
	if (visited[loc]) return dp[loc];
	if (dp[loc]) return dp[loc];
	if (ladders[loc]) loc = ladders[loc];
	if (snakes[loc]) loc = snakes[loc];
	visited[loc] = 1;
	dp[loc] = INF;
	for (int i = 1 ; i <= 6; i++){
		dp[loc] = std::min(dp[loc], 1 + minMoves(dp, snakes, ladders, visited, loc + i));
	}
	return dp[loc];
}
int main() {
	int testCases; cin >> testCases;
	while (testCases--){
		vector<int>snakes(101, 0);
		vector<int>ladders(101, 0);
		vector<int>dp(101,0);
		vector<int>visited(101,0);
		int l; cin >> l;
		for (int i = 0; i < l; i++){
			int a, b; cin >> a >> b;
			ladders[a] = b;
		}
		int s; cin >> s;
		for (int i = 0 ; i< s; i++){
			int a, b; cin >> a >> b;
			snakes[a] = b;
		}
		cout << minMoves(dp, snakes, ladders, visited, 1) << endl;
	}
}
