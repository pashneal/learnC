#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	vector<int> intv;
	stringstream ss(str);

	char delimiter;
	int a;
	ss >> a;
	intv.push_back(a);
	while (ss >> delimiter) {
		ss >> a;
		intv.push_back(a);
	}
	return intv;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(auto i = integers.begin(); i < integers.end(); ++i) {
        cout << *i << "\n";
    }
    
    return 0;
}


