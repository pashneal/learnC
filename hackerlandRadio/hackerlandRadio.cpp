/*
 * Puzzle Link: https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *    Could most likely be solved with dynamic programming in O(nk) time and space
 * 
 * There is in fact a greedy algorithm that works for this kind of problem
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
	vector<int>v(n);
	for (int i = 0; i< n; i++){
		cin >> v[i];
	}
	std::sort(v.begin(), v.end());

	int total = 0;
	int i = 0;
	while (i < n){
		int loc = v[i] + k;
		while (i < n && v[i] <= loc) i++;
		loc = v[--i] + k;
		total++;
		while (i < n && v[i] <= loc) i++;
	}
	cout << total;
}
