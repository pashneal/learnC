/*
 * Puzzle Link: https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=search
 * Puzzle Difficulty: Medium
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
#define INF 0x7FFFFFFF
#define INFL 0x7FFFFFFFFFFFFFFF
typedef std::pair<int, int> ipair;
using namespace std;

int main() {
	int testCases; cin >> testCases;
	while (testCases--){
		int money, n; cin >> money >> n;
		vector<int>v(n);
		unordered_map<int, vector<int>>count;
		for (int i = 0; i < n ; i++){
			cin >> v[i];
			if (count.find(v[i]) == count.end()) count[v[i]] = {};
			count[v[i]].push_back(i+1);
		}
		int a = -1;
		int b = -1;
		for (int i : v){
			if (count.find(money - i) != count.end()){
				if ((money - i) == i){
					if (count[i].size() < 2){
						continue;
					}
				}
				a = count[i].front();
				b = count[money - i].back();
				break;
			}
		}
		cout << min(a,b) << " " << max(a,b) << endl;
	}
}
