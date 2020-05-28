/*
 * Puzzle Link: https://www.hackerrank.com/challenges/larrys-array/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	we can sort the array to see where every value must be able to go
 *	then we can attempt a kind of insertion sort to get 
 *	elements to the correct values in O(n^2)
 *
 *	(there is possibly a way to find a contradiction in O(1) time though)
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
void swapIntoPlace (vector<int>& array, int index, int elementToSort){
	int i = index;
	while (i < (int)array.size()) {
		if (array[i] == elementToSort) 
			break;
		i++;
	}
	
	while (i != index) {
		int rotateAmount = std::min((i - index), 2);
		if (rotateAmount == 2) {
			// 2 1 0
			// 0 2 1
			int temp = array[i-1];
			array[i-1] = array[i-2];
			array[i-2] = array[i];
			array[i] = temp;
		} else {
			int temp = array[i - 1];
			array[i - 1] = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
		}
		i -= rotateAmount;
	}
	
}
int main() {
	int testCases; cin >> testCases;
	while (testCases--){
		bool  flag  = false;
		int lengthArray; cin >> lengthArray;
		int n = lengthArray;
		vector<int> array;
		array.reserve(lengthArray);

		while (n--){
			int in; cin >> in;
			array.push_back(in);	
		}

		for (int i = 0; i < lengthArray; i++){
			if (array[i] == i+1){
				continue;
			} else {
				if (i == lengthArray - 2){
					cout << "NO" << endl;
					flag = true;
					break;
				}
				swapIntoPlace(array, i, i+1);
			}
		}
		if(!flag)
			cout << "YES" << endl;
	}
}
