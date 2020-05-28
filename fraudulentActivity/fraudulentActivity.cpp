/*
 * Puzzle Link: https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
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
#include <list>
#include <deque>
using namespace std;
int main() {
	int expenditures, days;
	cin >> expenditures >> days;
	deque<int> trailing;
	deque<int> sorted;
	int numNotifications = 0;
	for (int i = 0 ; i < days; i++){
		int a; cin >> a;
		trailing.push_back(a);
	}
	expenditures -= days;
	sorted = trailing;
	std::sort(sorted.begin(), sorted.end());

	while (expenditures-- > 0){
		double median;
		if (days % 2) {
			median = sorted[days/2];
		} else {
			median = sorted[days/2 - 1] + sorted[days/2];
			median /= 2.0;
		}
		int a; cin >> a;
		if (a >= median*2.0) numNotifications++;
		sorted.erase(std::lower_bound(sorted.begin(), sorted.end(), trailing.front()));

		trailing.pop_front();
		trailing.push_back(a);
		auto iter = std::lower_bound(sorted.begin(), sorted.end(), a);
		if (iter == sorted.end()){
			sorted.push_back(a);
		} else {
			sorted.insert(iter, a);
		}
	}
	cout << numNotifications << endl;
}
