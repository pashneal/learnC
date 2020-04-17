#include <iostream>
#include <vector>

using namespace std;
int main() {
	int lenItems;
	cin >> lenItems;

	int didNotChooseIndex;
	cin >> didNotChooseIndex;
	int itemCostSum = 0;
	for (int i = 0; i < lenItems; i++) {
		
		int item;
		cin >> item;
		if (i != didNotChooseIndex) 
			itemCostSum += item;
	}

	int avg =  itemCostSum/2;
	int chargedAmount;
	cin >> chargedAmount;

	int expectedAmount = chargedAmount - avg;

	if (expectedAmount) {
		cout << expectedAmount;
	} else {
		cout << "Bon Appetit";
	}
}
