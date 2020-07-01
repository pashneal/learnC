/*
 * Puzzle Link: https://www.hackerrank.com/challenges/candies/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *		Go in the forward direction and make sure that every individual has 
 *		n + 1 candies or 1
 *
 *		Go in the reverse direction and make sure that every individual has
 *		n + 1 candies or keep the same amount
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
typedef std::pair<long, int> ipair;
using namespace std;

int main() {
	long n; cin >> n;
	vector<long>candies;
	for (long i = 0 ; i< n ; i++){
		long input; cin >> input;
		candies.push_back(input);
	}
	//give out at least one candy to every person
	vector<long>results(n, 1);
	for (long i = 1; i < n; i++){
		if (candies[i-1] < candies[i])
			results[i] = results[i-1] + 1;

	}
	for (long i = n-1; i > 0 ; i--){
		if (candies[i] < candies[i-1] && (results[i] >= results[i-1])) {
			results[i-1] = results[i] + 1;
		}
	}
	long total = 0; 

	for (auto i : results) {
		total += i;
	}
	cout << total << endl;
}
