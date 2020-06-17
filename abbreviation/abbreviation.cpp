/*
 * Puzzle Link: https://www.hackerrank.com/challenges/abbr/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *		on the first pass, see if upperCase letters of a - upperCase letters of b >= 0
 *		for all a; and make sure they are in the correct order
 *
 *		then from lowercase letters create longest common subsequence (LCS)
 *		from all capital letters
 *
 *		see if LCS == len(b)
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

long LCS(vector<vector<long>>& dp, string& a, string& b, long i, long j){
	if (j == (long)b.size()) return 0;
	if (i == (long)a.size()) return 0;
	if (dp[i][j] > -1) return dp[i][j];
	dp[i][j] = -INF;
	if (a[i] == b[j]) dp[i][j] = 1 + LCS(dp, a, b, i+1, j+1);
	dp[i][j] = max(dp[i][j] , LCS(dp, a, b, i+1, j));
	return dp[i][j];
}
bool capitalsMatch( string& a, string& b, long i, long j){
	if (i == (long)a.size()) return true;
	if (j == (long)b.size()) return false; 
	if (a[i] == b[j]) return capitalsMatch(a ,b , i+1, j+1);
	else return capitalsMatch(a, b, i, j+1);
}

int main() {
	long q; cin >> q;
	while (q--){
		string a, b; cin >> a >> b;
		vector<vector<long>>dp(a.size() , vector<long>(b.size(), -1));
		string aa = "";
		for (auto i: a)
			if (!(i &' '))
				aa+= i;
		if (!capitalsMatch(aa,b,0,0)) {
			cout << "NO" << endl;
			continue;
		} 
		for (char &i : a) i = i & '_';
		if (LCS(dp, a, b, 0, 0) == (long)b.size())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
}
