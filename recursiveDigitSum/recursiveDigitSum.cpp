/*
 * Puzzle Link: https://www.hackerrank.com/challenges/recursive-digit-sum/problem
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

long sum_digits( long num ) {
	long sum = 0;
	while (num){
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
long super_digit( long num){
	if (num < 10) return num;
	return super_digit(sum_digits(num));
}
int main() {
	string input; cin >> input;
	int k; cin >> k;
	long initial_super_digit = 0;
	for (auto character: input) initial_super_digit += character - '0';
	initial_super_digit *= k;
	cout <<  super_digit(initial_super_digit);
}
