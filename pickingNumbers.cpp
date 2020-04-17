#include <iostream>
#include <unordered_map>

int main() {
	int lengthNumbers;
	std::cin >> lengthNumbers;
	std::unordered_map <int, int> mapNumbers;
	while (lengthNumbers--) {
		int i;
		std::cin >> i;
		if (mapNumbers.find(i) == mapNumbers.end()) mapNumbers[i] = 0;
		mapNumbers[i]++;
	}

	int maxSelection = 0;
	for (auto iterator: mapNumbers) {
		int count = iterator.second;
		if (mapNumbers.find(iterator.first - 1) != mapNumbers.end())
			count += mapNumbers[iterator.first - 1];
		maxSelection = std::max(count, maxSelection);
		count = iterator.second;
		if (mapNumbers.find(iterator.first + 1) != mapNumbers.end())
			count += mapNumbers[iterator.first + 1];
		maxSelection = std::max(count, maxSelection);
	}

	std::cout << maxSelection;

}
