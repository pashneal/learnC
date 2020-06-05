/*
 * Puzzle Link: https://www.hackerrank.com/challenges/richie-rich/problem
 * Puzzle Difficulty: Medium 
 *
 * Initial Thoughts:
 *  we can first match up all the minimum necessary strings
 *  then we can match up all the strings to maximize the number
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
	int n , k ; cin >> n >> k;
	string s; cin >> s;
	unordered_set<int> m;
	//find necessary matches
	if (n % 2) m.insert( n / 2 );
	for (unsigned i = 0 ; i < s.size()/2; i++){
		if (s[i] != s[s.size() - i - 1]) {
			s[i] = std::max(s[i], s[s.size() - i - 1]);
			s[s.size() - i - 1] = std::max(s[i], s[s.size() - i - 1]);
			m.insert(i);
			if (--k < 0) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}
	//find extra matches
	for (unsigned i = 0 ; i < s.size() ; i++){
		if (s[i] == '9') continue;
		if ((k - 2 + (m.find(i) != m.end())) < 0) continue;
		k -= 2 + (m.find(i) != m.end());
		s[i] = '9';
		s[s.size() - i - 1] = '9';
	}
	cout << s << endl;
}
