#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
vector<int>dp;
int findTotal(set<int>& selected , map<int , int>& count) {
	int total = 0;
	for (int i: selected) {
		total+=count[i];
	}
	return total;
}
int findMaxSubset(int index, map<int, int>& count, set<int>& selected, int nonFactor) {
	if (index == nonFactor) return findTotal(selected, count);
	if (count.find(index) == count.end()) return findMaxSubset(index + 1, count, selected, nonFactor);

	cout << " HERE " << endl << "index " << index << endl;
	int maxScore = 0;
	bool flag = false;
	if (selected.find((nonFactor - index) % nonFactor) == selected.end()){
		selected.insert(index) ; flag = true;
		maxScore = findMaxSubset(index + 1, count, selected, nonFactor);
	}
	if (flag) selected.erase(index);
	maxScore = std::max(maxScore, findMaxSubset(index + 1, count, selected, nonFactor));
	cout << "maxScore at " << index << " = " << maxScore << endl;;
	return maxScore;
}

int main() {
	//parse the input
	int length;
	cin >> length;
	int nonFactor;
	cin >> nonFactor;

	if (nonFactor == 1) {
		cout << 1;
		return 1;
	}
	vector<int> inputVector;
	map <int , int > count;

	while(length--){
		int a; cin >> a;
		if (count.find(a % nonFactor) == count.end())
			count[a % nonFactor] = 0;
		count[a % nonFactor]++;
	}

	set<int>selected;
	for (int i = 0 ; i < nonFactor; i++) {
		dp.push_back(-1);
	}
	cout << findMaxSubset(0, count, selected, nonFactor);

}


