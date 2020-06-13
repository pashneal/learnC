/*
 * Puzzle Link: https://www.hackerrank.com/challenges/short-palindrome/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	We can count the unique characters and then use combinatorics to calculate
 *	the end result
 *
 * Secondary thoughts:
 *	we can simply brute force to find the best solution
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
long long mod = 1000000007u;
int main() {
	string s; cin >> s;
	int c1[26];
	int c2[26][26];
	int c3[26][26][26];
	int ans = 0;
	for (auto c : s) {
		int letter = c - 'a';
		for (int i = 0; i < 26; i++){
			ans += c3[letter][i][i];
			c3[i][letter][letter] += c2[i][letter];
			c2[i][letter] += c1[i];

			ans %= mod;
			c3[i][letter][letter] %= mod;
			c2[i][letter] %= mod;
		}
		c1[letter] += 1;
		c1[letter] %= mod;
	}
	cout << ans;
}
