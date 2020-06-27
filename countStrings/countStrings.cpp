/*
 * Puzzle Link: https://www.hackerrank.com/challenges/count-strings/problem
 * Puzzle Difficulty: Hard
 *
 * Initial Thoughts:
 *	(a | b | c) = monad; len(monad) = 3
 *	if the terms in monad* are all the same length. len(monad)^(max) - floor(len(monad)^(min))
 *	max = n; min = 0 , -1
 *	monad*n | monad -> monad
 *	(a | b .... )with no * = constant monad. len(monad) times rest of monads
 *	(aab | a)* ->  (aaa | aab)* + (a)
 *
 *	I cannot do this problem at this time as it requires working knowledge of 
 *	deterministic finite automata which I do not yet possess.
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
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}
