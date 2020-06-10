/*
 * Puzzle Link: https://www.hackerrank.com/challenges/ctci-bubble-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
 * Puzzle Difficulty: Easy
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
#define INF 0x7FFFFFFF;
typedef std::pair<int, int> ipair;
using namespace std;

int main() {
	int n; cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int swaps = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {
				a[j] ^= a[j+1];
				a[j+1] ^= a[j];
				a[j] ^= a[j+1];
				swaps++;
			}
		}
	}	
	printf("Array is sorted in %d swaps.\n", swaps);
	printf("First Element: %d\n", a[0]);
	printf("Last Element: %d", a[a.size()-1]);
}
