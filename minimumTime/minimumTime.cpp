/*
 * Puzzle Link: https://www.hackerrank.com/challenges/minimum-time-required/problem?h_l=longerview&playlist_slugs%5B%5D=longerview-preparation-kit&playlist_slugs%5B%5D=search
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *    Can most likely get away with a O(nk) solution where k is some small constant factor
 *    too lazy to code counting sort so O(n log n) will have to do
 *
 *    Attempted to code an incorrect algo that would not work
 *    correct approach is to set lower and upper bounds and then binary search to make
 *    the bounds converge on the correct answer
 *
 *    a good lower bound is floor(target/approximate_rate)
 *    namely, for every rate r in machines, approximate_rate = sum(r)
 *    this approximation will always underestimate the result.
 *
 *	  a good upper bound is ceil(2*target/approximate_rate)
 *	  this is the maximum case if approximate_rate has misestimated every machine
 *
 *	  O(n) to eval for every O(log n) check made
 *    
 *    O(n log n)
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

long eval (vector<long>&v ,long approx_days){
    long approx_items_made = 0;
    for (auto i : v) {
        approx_items_made += approx_days / i;
    }
    return  approx_items_made;
}
long binsearch(vector<long>&v, long target, long hi, long lo){
    if (lo > hi) return INFL;
    long mid = (hi + lo)/2;
    long num = eval(v, mid);
    if (num >= target) {
        return min(mid, binsearch(v, target, mid-1, lo));
    }
    return binsearch(v, target, hi, mid+1);
}
int main() {
    std::ios::sync_with_stdio(false);
    long n, target; cin >> n >> target;
    vector<long> v(n);
    double approx_rate = 0;
    for (long i = 0; i < n; i++){
        cin >> v[i];
        approx_rate += 1.0/v[i];
    }

    long approx_days = target / approx_rate;
    cout << binsearch(v, target, approx_days*2, approx_days);
}


