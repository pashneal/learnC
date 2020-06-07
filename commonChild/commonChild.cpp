/*
 * Puzzle Link: https://www.hackerrank.com/challenges/common-child/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	 Longest common substring problem solved by dynamic programming in O(n^2) time and space 
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
int bestCommonChild( int i, int j, string& a, string& b, vector<vector<int>>& dp){
	if (i >= (int)a.size() || j >= (int)b.size()) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (a[i] == b[j])
		dp[i][j] = bestCommonChild(i+1, j+1, a, b, dp) + 1; 
	int m = std::max( bestCommonChild(i+1,j,a,b,dp), bestCommonChild(i,j+1,a,b,dp));
	dp[i][j] = std::max(m , dp[i][j]);
	return dp[i][j];
}
int main() {
	string a , b; cin >> a >> b;
	vector<vector<int>>dp(a.size());
	for(auto& v: dp) v.resize(b.size(), -1);
	cout << bestCommonChild(0, 0, a, b, dp);
}
