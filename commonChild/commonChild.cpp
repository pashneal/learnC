/*
 * Puzzle Link: https://www.hackerrank.com/challenges/common-child/problem
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
using namespace std;
int bestCommonChild(int i, vector<int>& dp, string s1, string s2){
	if(i >= (signed)s1.size() || i >= (signed)s2.size()){
		return (s1 == s2) * s1.size();
	}
	if (dp[i] != -1){
		return dp[i];
	}
	int m = 0;
	if (s1[0] != s2[0]){
		if (s1.find(s2[0]) != string::npos) {
			m = bestCommonChild(i+1, dp, s1.substr(s1.find(s2[0]), s1.size()), s2);
			//delete from first string
		} if (s2.find(s1[0]) != string::npos) {
			//delete from second string
			m = std::max(bestCommonChild(i+1, dp, s1, s2.substr(s2.find(s1[0]), s2.size())), 
						m);
		}
		return m;
		
	} else {
		//ignore 	
		dp[i] = bestCommonChild(i+1, dp, s1.substr(0,s1.size()-1), s2.substr(0,s2.size()-1)) + 1 ;
		return dp[i];
	}
}
int main() {
	vector<int> dp;
	
	string  s1, s2;
	cin >> s1 >> s2;
	dp.resize(std::max(s1.size(), s2.size()), -1);
}
