
/*
 * Puzzle Link:https://www.hackerrank.com/challenges/kaprekar-numbers/problem
 * Puzzle Difficulty:Easy 
 *
 * Initial Thoughts:
 *	just need to brute force
 *	helpful optimizations
 *	x cannot be a keprekar number if
 *		x mod 9 != x*x mod 9 
 *		x mod 11 != x*x mod 11 (i'm kinda unsure about this)
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
	long long p,q;
	cin >> p;
	cin >> q;
	bool f = false;
	while(q >= p-1){
		long long x = p*p;
		if (p % 9 != x %  9 ){ // || q % 11 != x % 11){
			p++;
			continue;
		}
		long long int digits = (long long)log10(x) + 1;
		long int d = digits/2 + (digits % 2); 
		long qq = x/(long long)pow(10,d);
		long long int pp = x % (long long)pow(10,d);
			if(qq + pp == p) {
				cout << p << " ";
				f = true;
			}
		p++;
	}
	
	if (!f) cout << "INVALID RANGE"<< endl;
}
