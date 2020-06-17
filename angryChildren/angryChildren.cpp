/*
 * Puzzle Link: https://www.hackerrank.com/challenges/angry-children/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	O(n log n) solution
 *	sort, and then the difference between k-separated integers in the sorted array are candidates
 *	for the minimum difference.
 *	choose the smallest such difference
 *
 *
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
	int n, k; cin >> n >> k;
	vector<int>v(n);
	for (int i =0 ; i< n; i++){
		cin >> v[i];	
	}
	std::sort(v.begin(), v.end());
	int ans = INF;
	int i = 0;
	int j = k-1;
	while (j < n) ans = min(v[j++] - v[i++], ans);
	cout << ans;
}
