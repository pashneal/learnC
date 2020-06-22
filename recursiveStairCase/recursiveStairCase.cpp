/*
 * Puzzle Link: https://www.hackerrank.com/challenges/ctci-recursive-staircase/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking
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
#define INF 0x7FFFFFFF
#define INFL 0x7FFFFFFFFFFFFFFF
typedef std::pair<int, int> ipair;
using namespace std;
const long mod = 10000000007;
vector<long>dp(50,-1);
long staircase(int n){
	if (dp[n] > -1) return dp[n];
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	dp[n] = (staircase(n-1) + staircase(n-2) + staircase(n-3)) % mod;
	return dp[n];
}

int main() {
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	for (auto i : v) {
		cout << staircase(i) << endl;
	}
}
