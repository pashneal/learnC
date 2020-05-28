/*
 * Puzzle Link: https://www.hackerrank.com/challenges/short-palindrome/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	We can count the unique characters and then use combinatorics to calculate
 *	the end result
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
long long choose (int n, int k) {
	long long i =  1;
	int kn = n-k;
	while (n--) {
		i *= n+1;
		i %= mod;
	}
	while (k--){
		i /= k+1;
	}
	while (kn--){
		i /= kn+1;
	}
	return i;
}
int main() {
	string s; cin >> s;
	unordered_map <char, int> m;
	for  (auto letter : s){
		if (m.find(letter) == m.end()) 
			m[letter] = 0;
		m[letter]++;
	}
	long long  total = 0;
	for (auto iter: m){
		if (iter.second >= 4){
			total += choose(iter.second , 4);
			total %= mod;
		}
	}
	for (auto& i: m) {
		if (i.second >= 2) 
			i.second = choose(i.second, 2);
		else 
			i.second = 0;
	}
	for (auto i = m.begin(); i != m.end();) {
		int value = i->second;
		i = m.erase(i);
		for (auto j : m) {
			total += (value * j.second);
			total %= mod;
		}
	}
	cout << total << endl;
}
