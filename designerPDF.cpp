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
	//do input parsing
	vector<int> letterLengths;
	for (int i = 0 ; i < 26 ; i++){
		int a; cin >> a;
		letterLengths.push_back(a);
	}
	string word;
	cin >> word;

	
	//solve
	int height = 0;
	int width = word.size();
	for(unsigned i = 0 ; i < word.size(); i++) {		
		height = std::max(letterLengths[word[i] - 'a'], height);
	}
	cout << width * height;
	

}
