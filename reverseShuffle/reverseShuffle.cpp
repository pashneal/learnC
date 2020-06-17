/*
 * Puzzle Link: https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
 * Puzzle Difficulty: Advanced
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
	string s;  cin >> s;
	vector<int>v(26, 0);

	for (auto c: s){
		v[c - 'a'] += 1;
	}
	string ans = "";
	for (int i = 0; i < 26; i++){
		for (int j = 0; j < v[i]/2; j++){
			ans += 'a' + i;
		}
	}
	cout << ans;
}
