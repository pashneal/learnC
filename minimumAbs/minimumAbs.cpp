/*
 * Puzzle Link: https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
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
#define INF 0x7FFFFFFF
#define INFL 0x7FFFFFFFFFFFFFFF
typedef std::pair<int, int> ipair;
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>v;
	while (n--){
		int a ; cin >> a;
		v.push_back(a);
	}
	std::sort(v.begin(), v.end());
	int min = INF;
	for (int i =0 ;i < (int)v.size() - 1 ; i++){
		min = std::min(v[i+1] - v[i], min);
	}
	cout << min;

}
