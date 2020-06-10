/*
 * Puzzle Link: https://www.hackerrank.com/challenges/gridland-provinces/problem
 * Puzzle Difficulty: Hard
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
void rotcalc( string candidate, int rot, unordered_set<string>& found){
	while (rot++ != (int)candidate.size()){
		char temp = candidate[0];
		candidate.erase(0,1);
		candidate += temp;
		found.insert(candidate);
	}
};

void tour( vector<string>& grid, int start, unordered_set<string>& found) {
	int dx = 0, dy = 0;
	int x = 0;
	int y = start;
	int ndy[4] = {1, 0, -1, 0};
	if (start) {
		ndy[0] = -1;
		ndy[2] = 1;
	}
	string prefix;
	while ( x + dx  < (int)grid[0].size() ) {
		x += dx;
		y += dy;
		dy = ndy[(prefix.size()) % 4];
		dx = (prefix.size()) % 2;
		prefix += grid[y][x];
		if (!dx && ((x + 1) < (int)grid[0].size())) {
			string suffix = grid[(y+1) %2].substr(x);
			std::reverse(suffix.begin(), suffix.end());
			suffix = grid[y].substr(x + 1) + suffix;
			string combined = prefix + suffix;

			found.insert(combined);
			std::reverse(combined.begin(), combined.end());
			found.insert(combined);
		}
	}
	found.insert(prefix);
	std::reverse(prefix.begin() ,prefix.end());
	found.insert(prefix);
}

int main() {
	int pr ; cin >> pr;
	while (pr-- ) {
		int cols; cin >> cols;
		vector<string> p;
		for (int i = 0; i < 2; i++){
			string a; cin >> a;
			p.push_back(a);
		}
		string cc = p[1];
		string ccw = p[0];
		std::reverse( cc.begin() , cc.end());
		std::reverse( ccw.begin() , ccw.end());

		cc = p[0] + cc;
		ccw = p[1] + ccw;
		unordered_set<string> found;

		rotcalc(ccw, 0, found);
		rotcalc(cc, 0, found);
		tour( p, 0, found);
		tour( p, 1, found);
		set<string>f;
		for (auto i: found) f.insert(i);
		for (auto i: f) cout << i << endl;
		cout << found.size() << endl;
	}
}
