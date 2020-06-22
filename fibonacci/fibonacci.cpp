/*
 * Puzzle Link: https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking
 * Puzzle Difficulty:  Easy
 *
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

int fib (int n ) {
	if (n == 2) return 1;
	if (n == 1) return 1;
	if (n < 1) return 0;
	return (fib(n-1) + fib(n-2));
}
int main() {
	int n ; cin >> n; cout << fib(n);
}
