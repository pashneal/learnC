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
	string inputString;
	getline(cin, inputString);
	int cols;
	double length = sqrt(inputString.size());
	cols = ceil(length);

	int i = 0; vector<string> encryption(cols, "");
	for (auto letter: inputString){
		encryption[i] += letter;
		i++;
		i %= cols;
	}
	for (string i: encryption){
		cout << i << " ";
	}
	
}
