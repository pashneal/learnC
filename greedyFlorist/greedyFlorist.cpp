/*
 * Puzzle Link: https://www.hackerrank.com/challenges/greedy-florist/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
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

int main() {
	int n , k ; cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i< n; i++){
		cin >> v[i];
	}
	std::sort(v.begin(), v.end(), greater<int>());
	int i = 0;
	int total = 0;
	while(i < n) {
		int j = i +k;
		while (i < min(j,n)) {
			total += (i/k + 1) * v[i];
			i++;
		}
	}
	cout <<total;
}
