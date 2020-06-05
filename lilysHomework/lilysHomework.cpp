/*
 * Puzzle Link: https://www.hackerrank.com/challenges/lilys-homework/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *		I hypothesize that the array is beautiful if it is sorted
 *		for example consider the array [1...n]
 *
 *		I hypothesize that the array (of length > 2) is sorted if it is beautiful
 *		proof (very iffy?)
 *		length 2 array is trivially sorted
 *		
 *		make a length n sorted array of distinct integers
 *
 *		let us create a length n + 1 array whose new element not smaller than any value of
 *		the length n array
 *
 *		the difference is smallest with the new element if comes 
 *		   - after the max(length n array) if sorted ascending
 *		   - before the max(length n array) if sorted descending
 *
 *		thus the sorted variant is maintained and the length n + 1 array is beautiful
 *			
 *		now find minimum amount of swaps when we
 *			- swap to sort ascending
 *			- swap to sort descending
 *		and return
 *
 *		O(n log n) to sort + O(n^2) to find swaps
 *
 *	Secondary thoughts:
 *		timed out on a few cases
 *		since the numbers are distinct, we can use a hashtable for O(1) expected lookup so
 *		the algorithm is
 *		O(n log n) to sort + O(n) to find swaps
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
	
	//parse input
	unordered_map<int, int> locations;
	int length;
	cin >> length;
	vector<int> array(length);

	while(length--){
		cin >> array[length];
		locations[array[length]] = length;
	}
	
	vector<int> sa,sd;
	sa = array;
	std::sort(sa.begin(), sa.end());
	sd = sa;
	std::reverse(sd.begin() , sd.end());

	int va = 0;
	vector<int>v = array;
	auto l = locations;
	for (unsigned i = 0 ; i < array.size(); i++){
		if (v[i] != sa[i]) {
			va++;	
			auto f = l[sa[i]];

			v[f] = v[i];
			v[i] = sa[i];

			l[v[i]] = i;
			l[v[f]] = f;
		}
	}

	int vd = 0;
	v = array;
	l = locations;
	for (unsigned i = 0 ; i < array.size(); i++){
		if (v[i] != sd[i]) {
			vd++;	
			auto f = l[sd[i]];
			v[f] = v[i];
			v[i] = sd[i];

			l[v[i]] = i;
			l[v[f]] = f;
		}
	}

	cout << std::min(va, vd);
}
