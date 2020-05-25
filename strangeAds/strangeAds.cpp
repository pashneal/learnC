/*
 * Puzzle Link: https://www.hackerrank.com/challenges/strange-advertising/problem
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
	int n; cin >> n;
	int liked = 5, shared = 0, sum = 0;
	while (n--){
		shared = (liked/2);
		sum += shared;
		liked = (liked/2 ) * 3;
	}
	cout << sum << endl;
}
