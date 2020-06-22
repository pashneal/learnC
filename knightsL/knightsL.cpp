/*
 * Puzzle Link: https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	Seems like the best solution is brute force with a little bit of optimization
 *	(don't redo redundant searches)
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

int main() {
	int rows; cin >> rows;
	vector<vector<int>>solution(rows-1, vector<int>(rows-1, -1));
	for (int dy = 1; dy < rows; dy++){
		for (int dx = dy; dx < rows; dx++){
			set<ipair>moveSet = {
				{-dx, dy}, 
				{-dx , -dy},
				{-dy, dx},
				{-dy, -dx}, 
				{dx, dy},
				{dx , -dy},
				{dy, dx},
				{dy, -dx}
			};
			set<ipair> visited;
			vector<ipair> newFrontier = {{0,0}};
			int moves = 0;
			while (newFrontier.size()){
				vector<ipair> frontier = newFrontier;
				newFrontier.clear();
				for (auto p: frontier) {
					int x = p.first;
					int y = p.second;
					if (x >= rows) continue;
					if (y >= rows) continue;
					if (x < 0) continue;
					if (y < 0) continue;
					if (visited.find({x, y}) != visited.end()) continue;

					visited.insert({x,y});
					for (auto dxdy: moveSet){
						newFrontier.push_back({dxdy.first + x, dxdy.second + y});
					}
				}
				if (visited.find({rows-1,rows-1}) != visited.end()){
					solution[dx - 1][dy - 1] = moves;
					solution[dy - 1][dx - 1] = moves;
					break;
				}
				moves++;
			}
		}
	}
	for (auto &v : solution){
		for (auto ans: v){
			cout << ans << " ";
		}
		cout << endl;
	}
}
