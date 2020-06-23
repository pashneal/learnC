/*
 * Puzzle Link: https://www.hackerrank.com/challenges/maximum-subarray-sum/problem?h_l=longerview&playlist_slugs%5B%5D=longerview-preparation-kit&playlist_slugs%5B%5D=search
 * Puzzle Difficulty: Hard
 *
 * Initial Thoughts:
 *	Lets try to brute force the solution and see where we get O(n^2)
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
typedef std::pair<long, long> ipair;
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	long queries; cin >> queries;
	while (queries--){
		long max = 0;
		long n, m; cin >> n >> m;
		vector<long> v(n);
		for (long i = 0; i < n; i++){
			cin >> v[i];
		}
		for (long i = 1; i <= n; i++){
			long sum = 0;
			long j = 0;
			for (; j < i; j++){
				sum += v[i];	
				sum %= m;
			}
			max = std::max(sum, max);
			for (;j<n;j++){
				sum -= v[j-i];
				sum += v[j];
				sum %= m;
				if (sum < 0) sum += m;
				max = std::max(sum, max);
			}
		}
		cout << max << endl;
	}
}
