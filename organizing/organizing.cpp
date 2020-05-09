/*
 * Puzzle Link:https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	Key Idea: swaps maintain total count per container
 *
 *	count the number of items that a container can hold
 *	and see if the types can be shared equally amongst them
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
	int lengthQueries;
	cin >> lengthQueries; 

	while (lengthQueries--){
		int sizeMatrix;
		cin >> sizeMatrix;

		vector<int> containerLimit(sizeMatrix);
		vector<int> ballCount(sizeMatrix);

		for (int row = 0 ; row < sizeMatrix ; row++){
			for (int col = 0 ; col < sizeMatrix; col++){
				int input; cin >> input;
				containerLimit[col] += input;
				ballCount[row] += input;
			}
		}

		unordered_map<int , int> hashTable;
		for (int i : containerLimit) {
			if (hashTable.find(i) == hashTable.end()) {
				hashTable[i] = 0;
			}
			hashTable[i]++;
		}

		bool flag = true;
		for (int i : ballCount) {
			if (hashTable.find(i) != hashTable.end()){
				hashTable[i]--;
				if (!hashTable[i]) hashTable.erase(i);
			} else {
				flag = false; break;
			}
		}
		if (!flag) cout << "Impossible" << endl;
		else cout << "Possible" << endl;
		
	}
}
