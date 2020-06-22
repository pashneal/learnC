/*
 * Puzzle Link: https://www.hackerrank.com/challenges/crossword-puzzle/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking
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

void crossword(set<string>&words; vector<char>&grid

int main() {
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<vector<int>>grid(10);
	string input;
	for (auto& i : grid){
		getline(cin, input);
		for (auto c: input){
			if (c == '-') i.push_back(1);
			else i.push_back(0);
		}
		i.push_back(0);
	}
	grid.push_back(vector<int>(12,0));
	unordered_set<string> v;
	string s = "";
	getline(cin, input);
	for (auto c: input) {
		if (c == ';') {
			v.insert(s);
			s = "";
			continue;
		}
		s += c;
	}
	v.insert(s);
}
