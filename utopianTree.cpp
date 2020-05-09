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
int formula(int);
int main() {
	//parse input
	int numTestCases;
	cin >> numTestCases;
	vector <int> testCases;
	while(numTestCases--){
		int a; cin >> a;
		testCases.push_back(a);
	}

	for (auto n: testCases) {
		int power = 2 << ((n+1)/2);
		if (n % 2 == 0) {
			cout << power - 1 << endl;
		} else {
			cout << power - 2 << endl;
		}
	}

}

