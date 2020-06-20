/*
 * Puzzle Link: https://www.hackerrank.com/challenges/friend-circle-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *        I finally get to use disjoint set union data structure!
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

unordered_map<int , int> parent;
unordered_map<int , int> size;
int largest = -INF;

void makeSet(int v){
    if (parent.find(v) != parent.end()) return;
    parent[v] = v;
    size[v] = 1;
}
int findRoot(int v){
    if (parent[v] == v)
        return v;
    return parent[v] = findRoot(parent[v]);
}
void unionSet(int u, int v){
    int a = findRoot(u);
    int b = findRoot(v);
    if (a != b){
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        largest = max(size[a], largest);
    }
    cout << largest << endl;
}
int main() {
    int queries; cin >> queries;
    while (queries--){
        int u, v; cin >> u >> v;
        makeSet(u);
        makeSet(v);
        unionSet(u, v);
    }
}

