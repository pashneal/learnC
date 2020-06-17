/*
 * Puzzle Link: https://www.hackerrank.com/challenges/luck-balance/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms&h_r=next-challenge&h_v=zen
 * Puzzle Difficulty: Easy
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

int main() {
	int n, k; cin >> n >> k;
	int totalLuck =0; int luck;
	int important;
	vector<int>choose;
	for (int i = 0; i < n; i++){
		cin >> luck;
		cin >> important;
		if (!important)
			totalLuck += luck;
		else
			choose.push_back(luck);
	}
	std::sort(choose.begin(), choose.end(), greater<int>());
	for (int i = 0; i < min(k, (int)choose.size()); i++){
		totalLuck += choose[i];
	}
	for (int i = k; i < (int)choose.size(); i++){
		totalLuck -= choose[i];
	}
	cout << totalLuck;
}
