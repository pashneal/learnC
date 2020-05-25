/*
 * Puzzle Link: https://www.hackerrank.com/challenges/ashton-and-string/problem
 * Puzzle Difficulty: Advanced
 *
 * Initial Thoughts: 
 *	n = size of initial string
 *	There are O(n^2) substrings 
 *
 *	Can sort the initial string at the start  O(n log n)
 *	name sorted string s
 *
 *	have two moving pointers that pops from the back and pushes to front
 *	when a substring needs to be of a certain size, pop enough elements from 
 *	the initial string until it is or correct size
 *	also pop from s' = s
 *
 *	then get the next substring by popping back and popping from s'
 *	and also push front and push to s'
 *	put s' into a list l
 *	repeat for all sizes [1, 2 , ... len(s)-1]
 *	O(n^2 log n)
 *
 *	sort and concatenate
 *	O(n^2 log n)
 *	
 *  find the index k
 *  O(n^2)
 *  
 *
 *  MISUNDERSTOOD THE PROBLEM AND ONLY PASSED 5/12 TEST CASES =[
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
	std::ios::sync_with_stdio(false);
	
	//parse input 
	int testCases;
	cin >> testCases;
	while(testCases--){
		//parse input
		string initialString; cin >> initialString;
		int k; cin >> k;

		set<string> uniqueSubstrings;

		for (unsigned i = 1; i < initialString.size() ; i++) {
			string sub = initialString.substr(0,i-1);
			for (unsigned ii = 0 ; ii <= initialString.size() - i; ii++){
				sub += initialString[i-1+ii];
				uniqueSubstrings.insert(sub);
				sub = sub.substr(1,sub.size()-1);
			}
		}
		uniqueSubstrings.insert(initialString);

		string finalString;
		int l = 0;
		for (auto s: uniqueSubstrings) {
			finalString += s;
			l += s.size();
			if (l > k) break;
		}
		cout << finalString[k-1] << endl;

	}

}
