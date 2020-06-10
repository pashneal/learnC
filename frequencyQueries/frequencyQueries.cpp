/*
 * Puzzle Link:  https://www.hackerrank.com/challenges/frequency-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	
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
#define INF 0x7FFFFFFF;
typedef std::pair<int, int> ipair;
using namespace std;

int main() {
	int queries; cin >> queries;
	unordered_map<int, int> database;
	unordered_map<int, unordered_set<int>> frequencies;
	while (queries--){
		int type, value; cin >> type >> value;
		switch (type) {
			case 1:
				if (database.find(value) == database.end()) {
					database[value] = 0;
					frequencies[0].insert(value);
				}
				frequencies[database[value]].erase(value);
				database[value]++;
				frequencies[database[value]].insert(value);
				break;
			case 2:
				if (database.find(value) == database.end()) break;
				frequencies[database[value]].erase(value);
				database[value] = max(0, database[value]-1);
				frequencies[database[value]].insert(value);
				break;
			default:
				bool found = frequencies[value].size();
				cout << found << endl;
		}
	}
	
}
