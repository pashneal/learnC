#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n ; i++){
		std::cin >> arr[i];
	}

	int count = 0;
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j] > arr[i] && (arr[i] + arr[j]) %k == 0) count++;
		}
	}
	
	std::cout << count;
}
