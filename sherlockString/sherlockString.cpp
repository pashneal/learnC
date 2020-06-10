/*
 * Puzzle Link: 
 * Puzzle Difficulty: 
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
#define INF 0x7FFFFFFF;
typedef std::pair<int, int> ipair;
using namespace std;

int main() {
	string s; cin >> s;
	vector<int>v(26,0);
	for (auto c : s) v[c - 'a']++;
	set<int>ss;
	int correct = 0;
	for (auto i : v) {
		if (i == 0) continue;
		if (ss.find(i) != ss.end()){
			if (correct == 0)
				correct = i;
			else if (i != correct) {
				cout << "NO" << endl;
				return 0;
			}
		}
		ss.insert(i);

	}
	if (ss.size() > 2) {
		cout << "NO" << endl;
		return 0;
	}
	if (ss.size() == 1 || *ss.begin() == *ss.cbegin() - 1 || *ss.begin() == 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
