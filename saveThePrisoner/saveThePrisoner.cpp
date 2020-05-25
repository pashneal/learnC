/*
 * Puzzle Link: https://www.hackerrank.com/challenges/save-the-prisoner/problem
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
using namespace std;
int main() {
	int testCases; cin >> testCases;
	while (testCases--){
		int numPrisoners, numSweets, startPrisoner;
		cin >> numPrisoners >> numSweets >> startPrisoner;
		startPrisoner--;
		cout << ((startPrisoner + numSweets - 1) % numPrisoners) + 1 << endl;
	}
}
