/*
 * Puzzle Link:https://www.hackerrank.com/challenges/matrix-rotation-algo/problem
 * Puzzle Difficulty: Hard
 *
 * Initial Thoughts: 
 *	This is a brute forcing puzzle where the only difficulty
 *	lies in parsing the matrix
 *	The solution below was written very quickly and is mostly illegible
 *
 *	 gR (get radius function)
 *	go through every radius by traversing down, then left, then right, then up
 *	return the array of elements found by doing this
 *
 *	 pR (put radius function)
 *	take a 1D array and apply to to a 2D matrix by doing the same thing as gR
 *
 *	rotate 
 *	apply a rotation by shifting elements in the 1D array right with some overflow
 *	calculations
 *
 *
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
//start top left
vector<int> gR(vector<vector<int>>& v, int r){
	int cols  = v[0].size();
	int rows = v.size();
	int x = std::min(rows,cols)/2 - r - 1;
	int y = x;
	int ye, xe;
	ye = rows - x;
	xe = cols - x;

	vector<int> z;
	while ( y < ye){
		z.push_back(v[y][x]);
		y++;
	}
	y--;
	x++;
	while ( x < xe){
		z.push_back(v[y][x]);
		x++;
	}
	x--;
	y--;
	while ( y >= std::min(rows,cols)/2 - r - 1){
		z.push_back(v[y][x]);
		y--;
	}
	y++;
	x--;
	while ( x >= std::min(rows,cols)/2 - r){
		z.push_back(v[y][x]);
		x--;
	}
	return z;
}
void pR(vector<vector<int>>& v, int r , vector<int>& vi) {
	int cols  = v[0].size();
	int rows = v.size();
	int x = std::min(rows,cols)/2 - r - 1;
	int y = x;
	int ye, xe;
	ye = rows - x;
	xe = cols - x;

	int i = 0;
	while ( y < ye){
		v[y][x] = vi[i];
		i++;
		y++;
	}
	y--;
	x++;
	while ( x < xe){
		v[y][x] = vi[i];
		i++;
		x++;
	}
	x--;
	y--;
	while ( y >= std::min(rows,cols)/2 - r - 1){
		v[y][x] = vi[i];
		i++;
		y--;
	}
	y++;
	x--;
	while ( x >= std::min(rows,cols)/2 - r){
		v[y][x] = vi[i];
		i++;
		x--;
	}
}
vector<int> rotate(vector<int>&v, int am){
	vector<int> rv(v.size());
	for (unsigned i = 0 ; i < v.size(); i++){
		rv[(am+i) % v.size()] = v[i];
	}
	return rv;
}
int main() {
	int m,n,r;
	cin >>m >> n>> r;
	vector<vector<int>> v(m);
	for (auto& vi: v){
		for (int i = 0; i < n; i++){
			int a; cin >> a;
			vi.push_back(a);
		}
	}

	for (int i = 0 ; i < std::min(m,n)/2 ; i++){
		auto vi = gR(v,i);
		vi = rotate(vi, r);
		pR(v, i, vi);
	}
	for (auto vi: v) {
		for (auto i : vi) {
			cout << i << " ";
		}
		cout << endl;
	}
}
