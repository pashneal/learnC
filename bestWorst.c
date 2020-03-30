#include <vector>
#include <iostream>

using namespace std;

int main() {
	long long int min, max, length;
	cin >> length;
	cin >> min;
	max = min;

	int maxCount = 0;
	int minCount = 0;

	for (int i = 1; i < length; i++) {
		int n;
		cin >> n;
		if (n > max) {
			max = n;
			maxCount++;
		}

		if (n < min) {
			min = n;
			minCount++;
		}
			
	}

	printf("%d %d", maxCount, minCount);
}
