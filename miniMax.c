#include <iostream>
using namespace std;

int main() {

	long long arr[5];
	for (int  i = 0 ; i < 5 ; ++i ) {
		cin >> arr[i];
	}

	long long max = -1;
	max <<= 63;
	long long min = 1;
	min <<= 62;

	for (int i = 0; i < 5; i++){
		int ignored = i;
		long long sum = 0;
		for (int j = 0; j < 5; j++){
			if (j == ignored) continue;
			sum += arr[j];
		}

		max = (sum > max)? sum : max;
		min = (sum < min)? sum : min;
	}

	cout << max << " " << min;
}
