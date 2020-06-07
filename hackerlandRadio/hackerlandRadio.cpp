/*
 * Puzzle Link: https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *    Could most likely be solved with dynamic programming in O(nk) time and space
 * 
 * There is in fact a greedy algorithm that works for this kind of problem
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
int bestRadio(int i, int range, vector<int>&v , vector<int>&dp, unordered_map<int, int>& nexts){
    if (i >= (int)v.size()) return 0;
    if (dp[i]) return dp[i];
    dp[i] = 1000000;
    for (int j = nexts[i]-1; j >= i; j--){
        if (v[j] - range > v[i]) break;
        dp[i] = std::min(dp[i], bestRadio(nexts[j],range,v,dp,nexts) + 1);
    }
    return dp[i];
}
int main() {
    int length, range;    cin >> length >> range;
    vector<int>dp(length, 0);
    vector<int> v(length);
    for (int i = 0 ; i < length ; i ++ ) { cin >> v[i]; }
    unordered_map<int,int> nexts;
    std::sort(v.begin(), v.end());
    for (auto j = 0; j < (int)v.size(); j++) {
            int next = j;
            while (next < (int)v.size() && v[next] - range <= v[j]) next++;
            nexts[j] = next;
    }
    cout <<    bestRadio(0,range,v,dp,nexts);
}

