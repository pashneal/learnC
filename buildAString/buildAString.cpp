/*
 * Puzzle Link: https://www.hackerrank.com/challenges/build-a-string/problem 
 * Puzzle Difficulty: Hard
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
int a, b, worth, n;
string s;
int solve(vector<int>&dp,  unordered_map<string, vector<int>>& m, int i){
    if (i >= n) return 0;
    if (dp[i]) return dp[i];
    dp[i] = INF;
    if (n - i >= worth){
        //find the longest substring of at least worth length
        int l = 0;
        for (auto j : m[s.substr(i,worth)]){
            int c = worth;
			if (j+c >  i) continue;
            while (j+c < i && i+c < n && s[i+c] == s[j+c]){
                c++;
            }
            l = max(c,l);
        }
        //if found
        if (l >= worth){
            dp[i] = b + solve(dp, m, i+l);
        }
    } 
    dp[i] = min(dp[i], a + solve(dp, m,i+1));
    return dp[i];
}

int main() {
    int testCases; cin >> testCases;
    while (testCases--){
        cin >> n >> a >> b >> s;
        unordered_map<string, vector<int>>m;
        vector<int>dp(n,0);
        worth = ceil((float)b/a);
        if (worth)
            for (int j = 0; j <= n - worth; j++)
                m[s.substr(j,worth)].push_back(j);

        cout << solve(dp, m ,0) << endl;
    }

}

