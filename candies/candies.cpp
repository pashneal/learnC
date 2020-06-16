/*
 * Puzzle Link: https://www.hackerrank.com/challenges/candies/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *		Count the number of unique neighbors that are smaller than the given number and
 *		add 1 to it
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
	int n ; cin >> n;
	vector<int>candies(n+1,0);
	for (int i = 0 ; i < n ; i++){
		cin >> candies[i];
	}
	vector<int>solution(n,0);
	solution[0] = 1;
	for (int i = 1; i < n ; i++){
		if (solution[i] > solution[i-1]) solution[i] = solution[i-1] + 1;
		else solution[i] = 1;
	}
	for (int i = n-2; i >= 0; i--){
		if (solution[i] > solution[i+1]) solution[i] = solution[i+1] + 1;
	}
	int total = 0;
	for (int i = 0 ; i < n; i++)
		total += solution[i];
	cout <<total;
}
