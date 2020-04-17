#include <iostream>
#include <map>

int main() {
	std::map < int ,int> pairs;
	int lengthOfArray;
	std::cin >> lengthOfArray;

	for (int i = 0 ; i < lengthOfArray; i++){
		int n;
		std::cin >> n;
		if (pairs.find(n) == pairs.end() ) {
			pairs[n] = 0;
		}

		pairs[n]++;
	}

	int total = 0;
	for (auto iterator: pairs) {
		total += iterator.second/2;
	}

	std::cout << total;
}
