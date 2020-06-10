/*
 * Puzzle Link: https://www.hackerrank.com/challenges/mark-and-toys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting&h_r=next-challenge&h_v=zen
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
#include <queue>

#define INF 0x7FFFFFFF;
typedef std::pair<int, int> ipair;
using namespace std;

int main() {
	int n, money; cin >> n >> money;
	vector<int>prices(n);
	for (int i = 0; i < n; i++){
		cin >> prices[i];
	}
	std::make_heap(prices.begin(), prices.end(), greater<int>());
	int total = 0;
	while (prices.size() && money - prices.front() >= 0) {
		money -= prices.front();
		total++;
		std::pop_heap(prices.begin(), prices.end() , greater<int>());
		prices.pop_back();
	} 
	cout << total << endl;
		
}
