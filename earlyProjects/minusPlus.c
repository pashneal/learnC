#include <iostream>
#include <vector>
using namespace std;

int main() {
	int arrayLength;

	cin >> arrayLength;
	vector<int> listOfThings;
	int numPositiveNegativeZero[] = {0, 0, 0};
	int input;
	for (int i = 0; i < arrayLength; i++){
		cin >> input;
		listOfThings.push_back(input);
		if (input == 0) numPositiveNegativeZero[2] += 1;
		if (input > 0) numPositiveNegativeZero[0] += 1;
		if (input < 0) numPositiveNegativeZero[1] += 1;
	}

	for (int numerator : numPositiveNegativeZero){
		float ratio = (float) numerator / arrayLength;
		cout << ratio << endl;
	}

}
