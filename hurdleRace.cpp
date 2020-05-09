#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <unordered_map>
using namespace std;
int main() {
	//do some parsing of the input
	int length;
	cin >> length;
	int initialHeight;
	cin >> initialHeight;
	vector<int> hurdles;
	int max = -1;
	while (length--) {
		int a;
		cin >> a;
		hurdles.push_back(a);
		max = std::max(a,max);
	}

	//solve
	cout << std::max(0, max - initialHeight);
}
