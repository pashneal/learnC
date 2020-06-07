/*
 * Puzzle Link: https://www.hackerrank.com/challenges/gridland-metro/problem
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
using namespace std;
int main() {
	vector<set<pair<int, int>>> tr;
	int n , m ; cin >> n >> m;
	int k; cin >> k;
	while (k--) {
		int i ; cin >> i;
		int a, b; cin >> a >> b;
		tr[i].insert({a,b});
	}
	int total = m*n;
	for (auto v: tr) {
		vector<pair<int, int>>found;
		a 
		for (auto p: v){
					
		}
	}
	cout << total;
}
