
/*
 * Puzzle Link: https://www.hackerrank.com/challenges/ctci-comparator-sorting/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting&h_r=next-challenge&h_v=zen
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
#define INF 0x7FFFFFFF;
typedef std::pair<int, int> ipair;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector< pair<int, string> > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
		players.push_back({score, name});
    }

    sort(players.begin(), players.end());
	for (int i = 0; i < n ; i++){
		cout << players[i].second << " " << players[i].second << endl;
	}
    return 0;
}
