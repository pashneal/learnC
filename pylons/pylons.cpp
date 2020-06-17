/*
 * Puzzle Link: https://www.hackerrank.com/challenges/pylons/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	At first I thought it was a space-filling greedy algorithm problem however
 *	greedy algo fails for the following case
 *
 *	0 0 1 1 1 1 0 0 0 0
 *  <---^----->
 *  0 0 1 1 1 1 0 0 0 0
 *  <-----^----->
 *		 <----^----->
 *
 *	Might still be able to get greedy 
 *	In fact, greedy algorithm *does* still work
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
	vector<int>v(n + k,0);
	for (int i =0 ; i< n; i++){
		cin >> v[i];
	}
	int i = 0;
	int total = 0;
	while (i < n) {
		int j = i+k-1;
		while (j > max(0,i-k) && !v[j]) j--;
		if (!v[j]) {
			cout << -1 << endl;
			return 0;
		}
		v[j] = 0;
		i = j+k;
		total++;
	}
	if (total == 0) cout << -1 << endl;
	else cout << total << endl;

}
