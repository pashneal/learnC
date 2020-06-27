/*
 * Puzzle Link: https://www.hackerrank.com/challenges/sansa-and-xor/problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign
 * Puzzle Difficulty:  Medium 
 *
 * Initial Thoughts:
 *		there is a mathematical formula that gives the number of counts
 *		but it can also be distilled into a simplier pattern recognition exercise
 *		
 *		when I solved this initially I thought of the mathematical approach first so..
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
typedef std::pair<int, int> ipair;
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int queries; cin >> queries;
	while( queries--){
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		vector<int>a(n);
		int j = 1;
		for (int i = 0 ; i < n/2 ; i++){
			a[i] = j++;
		}
		if (n % 2 == 0) j--;
		for (int i = n/2; i < n; i++){
			a[i] = j--;
		}
		int total = 0;
		for (int i = 0; i < n; i++){
			if ((a[i]*(a[i]+1) + (n - 2*a[i])*a[i] ) % 2){
				total ^= v[i];
			}
		}
		cout << total << endl;
	}
}
