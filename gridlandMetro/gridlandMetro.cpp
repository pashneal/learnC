/*
 * Puzzle Link: https://www.hackerrank.com/challenges/gridland-metro/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *		This is a matter of iterating through the queries of the range
 *		The initial way I thought of doing this is to manage a set of ranges
 *		with operations to combine ranges on the fly
 *
 *		<------->    <------->
 *			<---------> 
 *
 *			turns into 
 *
 *		<-------------------->
 *
 *		by using a set to order the start of every range and working from there
 *		A much simpler implementation would be to take all queries first, sort,
 *		and then build every range from there
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

typedef std::pair<long, long> ipair;
using namespace std;

//deletes a range that includes the specified bounds
//returns the min lhs and max rhs deleted
//returns {a,b} if nothing is found in the range
//ipair delete_range(long a, long b, set<ipair>& ranges){
	//auto result = ranges.lower_bound({a, b});
	//if (result != ranges.begin()){
		//result--;
	//}
	//while (result != ranges.end()){
		//if (result -> second < a) { 
			//result++;
			//continue;
		//}
		//if (result -> first > b) break;
		//a = min(a, result->first);
		//b = max(b, result->second);
		//result = ranges.erase(result);
	//}
	//return {a, b};
//}
//void insert_range(ipair range , set<ipair>& ranges){
	//auto new_range = delete_range(range.first , range.second, ranges);
	//ranges.insert(new_range);
//}
//int main() {
	//long rows , columns , numRanges; cin >> rows >> columns >> numRanges;
	//unordered_map<int , set<ipair>>gridlandMetros;
	//while (numRanges--){
		//long row, col1, col2; cin >> row >> col1 >> col2;
		//if (gridlandMetros.find(row) == gridlandMetros.end())
			//gridlandMetros[row] = {};
		//insert_range({col1, col2}, gridlandMetros[row]);
	//}
	//long ans = 0;
	//for (auto & row : gridlandMetros){
		//for (auto range : row.second){
			//ans += (range.second - range.first + 1);
		//}
	//}
	//ans = rows * columns - ans;
	//cout << ans;
//}


//second implementation
int main() {
	unordered_map <int, vector<ipair>> gridlandMetros;
	long rows , columns , numRanges; cin >> rows >> columns >> numRanges;
	while (numRanges--){
		long row, col1, col2; cin >> row >> col1 >> col2;
		if (gridlandMetros.find(row) == gridlandMetros.end())
			gridlandMetros[row] = {};
		gridlandMetros[row].push_back({col1, col2});
	}
	long ans = rows * columns;
	for (auto &v: gridlandMetros){
		std::sort(v.second.begin(), v.second.end());
		long a = 0 ; long b = -1 ;
		for (long i = 0 ; i < (long)v.second.size(); i++){
			long begin = v.second[i].first;
			long end = v.second[i].second;
			if (begin > b){
				ans-= 1 + b - a;
				a = begin;
				b = end;
			} else {
				b = max(b, end);
			}
		}
		ans -= 1 + b - a;
	}
	cout << ans;

}
