/*
 * Puzzle Link: https://www.hackerrank.com/challenges/bigger-is-greater/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	choose smallest index k
 *	where there is some string[i] < string[k] and i is in {0, 1, ...k-1}
 *	if no such index exists, return "no answer"
 *	can be found in O(n^2) and probably O(nlog(n))
 *
 *	then, find index h such that
 *  h in {0...k}
 *  and all string[i] >= string[i+1] for i in {h+1...k}
 *
 *	find the next highest element in substring[h+1:]
 *	lexographically sort the substring[h+1:] 
 *	find the answer from there O(n)
 *  
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
	int length;
	cin >> length;
	while(length--){
		string testCase;
		cin >> testCase;

		int k = testCase.size();
		bool flag = false;
		while(k--){
			for (int i = 0;i < k; i++){
				if (testCase[i] < testCase[k]){
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (k == -1){ cout << "no answer" << endl; continue;}

		int h = k;
		while(h){
			h--;	
			if (testCase[h] < testCase[h+1])
				break;
		}
		string substring;
		string prefix;
		char nextHighest = 'z'+1;
		int nextHighestIndex = -1;
		for (unsigned i = h; i < testCase.size(); i++){
			if (testCase[i] > testCase[h]){
				if (nextHighest >= testCase[i]){
					nextHighest = testCase[i];
					nextHighestIndex = i;
				}
			}
		}
		

		testCase.erase(nextHighestIndex,1);
		prefix = testCase.substr(0,h);
		prefix += nextHighest;
		testCase = testCase.substr(h);
		std::sort(testCase.begin(), testCase.end());
		prefix += testCase;
		cout << prefix << endl;
	}
}
