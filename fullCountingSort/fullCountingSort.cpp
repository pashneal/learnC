/*
 * Puzzle Link: https://www.hackerrank.com/challenges/countingsort4/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *  use the builtin tuple class and stable sort
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
bool comp(pair<int, string> a, pair<int , string>  b){
	return a.first < b.first;
}
int main() {

	int length; cin >> length;

	vector<pair<int , string>>l;
	int n;
	string s;
	while(cin >> n >> s){
		if ((int) l.size() < length/2) s = "-";
		l.push_back({n, s});	
	}
	std::stable_sort(l.begin(), l.end(), comp);
	for (auto i: l) cout << i.second << " ";

}
