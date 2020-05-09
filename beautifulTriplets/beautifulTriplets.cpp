/*
 * Puzzle Link:https://www.hackerrank.com/challenges/beautiful-triplets/problem
 * Puzzle Difficulty: Easy 
 *
 * Initial Thoughts:
 *	put all indices in a hash table; O(n)
 *
 *	can iterate over sorted set of unique numbers using two indices
 *	at k and j where (k > j). then calculate if d + a[j] == a[k] - d == a[i] for some i in hashtable
 *	this can be done in O(n^2)
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
	int length;
	cin >> length;
	int d;
	cin >> d;
	unordered_set<int> hashtable;
	vector<int> v;
	while(length--){
		int a; cin >>a;
		hashtable.insert(a);
		v.push_back(a);
	}
	int count = 0;
	for( unsigned j = 0; j < v.size(); j++){
		for (unsigned k = j; k < v.size() ; k++){
			if(v[j] + d == v[k] - d){
				if (hashtable.find(v[j] +d) != hashtable.end())
						count++;
			}
		}
	}
	cout << count;
	
}
