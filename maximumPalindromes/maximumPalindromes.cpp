/*
 * Puzzle Link: https://www.hackerrank.com/challenges/maximum-palindromes/problem
 * Puzzle Difficulty: Medium
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
long long mod = 1000000007u;
long long perm(int numerator, vector<int> dups){	
	long long result = 1;
	for (int i = 1; i <= numerator; i++){
		result *= i;
		result %= mod;
	}
	for (int i : dups){
		i++;
		while (--i)
			result /= i;
	}
	return std::max(result, 1ll);
}
int main() {
	string s; cin >> s;
	int testCases; cin >> testCases;
	while (testCases--){
		int l , r; cin >> l >> r;
		l--;
		string ss = s.substr(l, (r-l));
		
		unordered_map <char, int> maps;
		for (auto i: ss){
			if (maps.find(i) == maps.end())
				maps[i] = 0;
			maps[i]++;
		}
		int singles = 0;
		int doubles = 0;
		vector<int> dups;
		for (auto i : maps){
			singles += i.second % 2;
			doubles += i.second / 2;
			dups.push_back(std::max(i.second/2, 1));
		}
		if ( singles != 0 ) {
			cout << (perm(doubles, dups) * singles  ) % mod << endl;
		} else 
			cout << (perm(doubles, dups)) % mod << endl;
	}
}
