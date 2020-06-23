/*
 * Puzzle Link: https://www.hackerrank.com/challenges/max-array-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dynamic-programming
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	We can safely ignore every negative number except for the largest one
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

long maxArraySum(vector<int>&v, vector<long>&dp, int index){
	if (index >= (int)v.size()) return 0;
	if (dp[index] != -INFL) return dp[index];
	dp[index] = v[index] + maxArraySum(v, dp, index + 2);
	dp[index] = max(dp[index] , maxArraySum(v, dp, index + 1));
	return dp[index];
}
int main() {
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n);
	bool allNegative = true;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		if (v[i] > 0) allNegative = false;
	}
	vector<long> dp(n, -INFL);

	if (allNegative) cout << *max_element(v.begin(), v.end());
	else cout << maxArraySum(v, dp, 0);
}
