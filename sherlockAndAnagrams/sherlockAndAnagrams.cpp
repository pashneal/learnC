/*
 * Puzzle Link: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *		use a math formula to count all pairs after sorting each anagramatic string
 *		and storing in a map.
 *		O(n^2 log n)  -  could probably do a little better with sorting
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
	int query ; cin >> query;
	while (query--){
		string test; cin >> test;
		int total = 0;
		for (unsigned i =1 ; i < test.size() ; i++) {
			unordered_map<string, int> stored_pairs;
			for (unsigned j = 0 ; j <= test.size()-i; j++){
				string anagram = test.substr(j,i);
				std::sort(anagram.begin(), anagram.end());
				if (stored_pairs.find(anagram) == stored_pairs.end()) 
					stored_pairs[anagram] = 0;
				stored_pairs[anagram]++;
			}
			for (auto iter : stored_pairs){
				total += iter.second * (iter.second - 1) * .5;
			};
		}
		cout << total << endl;
	}
}
