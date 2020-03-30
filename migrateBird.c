#include <iostream>

using namespace std;
int main() {
	int length;
	int hashTable[5] = {0};
	
	cin >> length;

	for (int i = 0; i < length; i++) { 
		int n;
		cin >> n;
		hashTable[n-1]++;
	}	

	int  max = -1;
	int  maxIndex = 0;
	for (int i = 0; i < 5; i++) { 
		if (hashTable[i] > max) {
			max = hashTable[i];
			maxIndex = i;
		}
	} 

	cout << maxIndex + 1;
}
