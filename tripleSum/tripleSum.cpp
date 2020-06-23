/*
 * Puzzle Link: https://www.hackerrank.com/challenges/triple-sum/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *		I first misread the statement and thought that a O(n^3) solution was necessary
 *		However i found a better O(n log n) solution
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
	int a, b, c; cin >> a >> b >> c;
	vector<int>lengths{a,b,c};
	vector<vector<int>>v(3);
	vector<set<int>>vv(3);
	int j = 0;
	for (int length: lengths){
		for (int i = 0 ; i < length; i++){
			int input; cin >> input;
			v[j].push_back(input);
		}
		vv[j] = set<int>(v[j].begin(), v[j].end());
		v[j] = vector<int>(vv[j].begin(), vv[j].end());
		j++;
	}

	long count = 0;
	
	for (auto i : v[1]){
		auto aa = upper_bound(v[0].begin(), v[0].end(), i);
		auto bb = upper_bound(v[2].begin(), v[2].end(), i); 
		count += (aa - v[0].begin()) * (bb - v[2].begin());
	}

	cout << count << endl;
}
