/*
 * Puzzle Link: https://www.hackerrank.com/challenges/non-divisible-subset/problem
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
	int n, k; cin >> n >> k;
	vector<int>v(k,0);
	while(n--) {
		int a; cin >> a;
		a %= k;
		v[a]++;
	}
	v[0] = min(v[0], 1);

	int total = 0;
	if (k%2 == 0) total += min(v[k/2], 1);
	for (int i =0; i< k/2 + k%2; i++){
		total += max(v[i], v[(k-i)%k]);
	}
	cout << total;

}
