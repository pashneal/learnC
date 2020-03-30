#include <vector> 
#include <string>
#include <set>
#include <iostream>

using namespace std;

int main() {
	int length;
	cin >> length;
	set<char>  gemstones;

	for (int i = length; i > 0; i--){
		string minerals;
		cin >> minerals;
		if (i == length) {
			for (char st: minerals) gemstones.insert(st);
		}
		set<char> testSet;
		for (char st: minerals) {
			testSet.insert(st);
		}

		vector <char> rejected;
		for (auto gemstone = gemstones.begin(); gemstone != gemstones.end(); gemstone++) {
			if (testSet.find(*gemstone) == testSet.end()) rejected.push_back(*gemstone);
		}
		for (char gemstone: rejected) {
			gemstones.erase(gemstone);
		}
	}
	cout << gemstones.size();
}
