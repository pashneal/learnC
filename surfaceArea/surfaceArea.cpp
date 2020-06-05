/*
 * Puzzle Link: https://www.hackerrank.com/challenges/3d-surface-area/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	There are six possible exposed faces per block
 *	so for every height given, see if there are bordering heights that obstructs that 
 *	any of the six given faces
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
	int h, w; cin >> h >> w;
	vector<vector<int>> grid(h);
	for (auto& v: grid){
		v.resize(w);
		for (auto i = 0 ; i < w ; i++){
			cin >> v[i];
		}
	}

	int total = 0;
	for (auto y = 0 ; y < h; y++){
		for (auto x = 0; x < w; x++){
			int blockHeight = grid[y][x];
			//every block will at least be exposed at the top and bottom
			int exposedFaces = 2;
			//assume that E, N, W, S are all not exposed 
			exposedFaces += 4*blockHeight;
			// correct assumptions
			if ( y > 0 ) exposedFaces -= std::min(grid[y-1][x], blockHeight);	
			if ( x > 0 ) exposedFaces -= std::min(grid[y][x-1], blockHeight);	
			if ( x < w-1 ) exposedFaces -= std::min(grid[y][x+1], blockHeight);	
			if ( y < h-1 ) exposedFaces -= std::min(grid[y+1][x], blockHeight);	
			
			total += exposedFaces;
		}
	}
	cout << total << endl;
}
