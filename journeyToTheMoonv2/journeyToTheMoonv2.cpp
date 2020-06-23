/*
 * Puzzle Link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	Resolving the problem using a more effecient data structure (disjoint union-find set)
 *	It is probably overkill, but it is also good practice so 
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

unordered_map<long, long> parent;
unordered_map<long, long> size;
void makeSet(long u){
	if (parent.find(u) != parent.end()) return;
	size[u] = 1;
	parent[u] = u;
	
}
long findRoot(long u){
	if (parent[u] == u) return u;
	return parent[u] = findRoot(parent[u]);
}
void combine(long u, long v){
	long a = findRoot(u);
	long b = findRoot(v);
	if (a == b) return;
	if (size[a] > size[b]) swap(a,b);
	size[b] += size[a];
	parent[a] = b;
}
int main() {
	std::ios::sync_with_stdio(false);
	long n, p; cin >> n >> p;
	for (long i = 0; i < n; i++){
		makeSet(i);
	}
	for (long i = 0; i < p; i++){
		long u, v; cin >> u >> v;
		combine(u, v);
	}
	unordered_set<long> roots;
	for (auto i : parent){
		roots.insert(findRoot(i.first));
	}
	long total =0;
	long ans = 0;
	for (auto i : roots){
		total += size[i];
	}
	for (auto i: roots){
		total -= size[i];
		ans += size[i]*total;
	}
	cout << ans;
}
