/*
 * Puzzle Link: https://www.hackerrank.com/challenges/alternating-characters/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
 * Puzzle Difficulty: Easy
 *
 * Initial Thoughts:
 *
 *	have a counter that resets at every AB and BA boundary and adds to total
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
#define INF 0x7FFFFFFF;
typedef std::pair<int, int> ipair;
using namespace std;

int main() {
	int testCases; cin >> testCases;
	while (testCases--){
		string s ; cin >> s;
		int n = s.size();
		long total = 0;
		int counter = 0;
		for (int i = 0; i < n -1; i++){
			if (s[i] == s[i+1]){
				counter++;	
			} else {
				total += counter;
				counter = 0;
			}
		}
		total += counter;
		cout << total << endl;
	}
}
