#include <iostream>

int main() {
	int valleys = 0;
	int numSteps;
	int elevation = 0;
	int prevElevation = -1;
	std::cin >> numSteps;
	std::string steps;
	std::cin >> steps;
	for (char step: steps) {
		prevElevation = elevation;
		if (step == 'U') {
			elevation++;
		} else {
			elevation--;
		}
		if (elevation == 0 && prevElevation < 0) valleys++;
	}
	
	std::cout << valleys;

}
