/*
 * Puzzle Link: https://www.hackerrank.com/challenges/ctci-merge-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
 * Puzzle Difficulty: Hard
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
void mergeSort(int hi, int lo, vector<int>&v, long& inversions){
	if ((hi - lo) < 1) return;
	int mid = (hi + lo) /2;
	int m = mid + 1;
	vector<int>n(hi-lo+1);
	int i = 0;
	int j = lo;
	mergeSort(mid, lo, v, inversions);
	mergeSort(hi, mid + 1, v, inversions);
	while (lo <= mid && m < hi + 1){
		if (v[lo] > v[m]){
			inversions += m-i+j;
			n[i++] = v[m++];
		} else {
			n[i++] = v[lo++];
		}
	}
	while (lo <= mid) 
		n[i++] = v[lo++];
	while (m < hi + 1){
		n[i++] = v[m++];
	}
	i =0;
	for (;j<=hi;j++){
		v[j] = n[i++];
	}
}
int main() {
	int testCases; cin >> testCases;
	while (testCases--){
		int length; cin >> length;
		long inversions = 0;
		vector<int>v(length);
		for (int i =0 ; i < length; i++)
			cin >> v[i];
		mergeSort(length - 1 , 0, v, inversions);
		cout << inversions << endl;
	}
}
