#include <vector>
#include <iostream>
#include <unordered_map>

int main() {
	int budget, numKeyboards, numUSBs;
	std::cin >> budget >> numKeyboards >> numUSBs;
	std::vector <int> keyboards;
	std::vector <int> USB;
	for (int i = 0; i < numKeyboards; i++ ) {
		int n;
		std::cin >> n;
		keyboards.push_back(n);	
	}

	for (int i=0; i< numUSBs; i++) {
		int n;
		std::cin >>n;
		USB.push_back(n);
	}

	int max = -1;
	for (int usbCost: USB) {
		for (int keyboardCost: keyboards) {
			if (usbCost + keyboardCost > max && usbCost + keyboardCost <= budget) {
				max = usbCost + keyboardCost;
			}
		}
	}

	std::cout << max;
}
