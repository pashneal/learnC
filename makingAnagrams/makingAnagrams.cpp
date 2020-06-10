/*
 * Puzzle Link: https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
 * Puzzle Difficulty: Easy
 *
 * Initial Thoughts:
 *	We can simply count the differences between the two strings
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
	string string1, string2; cin >> string1 >> string2;
	unordered_map<char, int>count1;
	unordered_map<char, int>count2;
	for (auto i : string1){
		if (count1.find(i) == count1.end()) count1[i] = 0;
		count1[i]++;
	}
	for (auto i : string2) {
		if (count2.find(i) == count2.end()) count2[i] = 0;
		count2[i]++;
	}
	int ans = 0;
	for (auto iter: count1){
		if (count2.find(iter.first) == count2.end()) count2[iter.first] = 0;
		ans += abs(count2[iter.first] - iter.second);
		count2[iter.first] = iter.second;
	}
	for (auto iter: count2){
		if (count1.find(iter.first) == count1.end()) count1[iter.first] = 0;
		ans += abs(count1[iter.first] - iter.second);
	}
	cout << ans;
	
}
