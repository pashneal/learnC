#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int lcm( int a, int b) {
	return a * b / gcd(a,b);
}
int main() { 
	int length1, length2;
	cin >> length1 >> length2;
	vector<int> v1, v2;
	
	for (int i = 0; i < length1; i++) {
		int n;
		cin >> n;
		v1.push_back(n);
	}
	for (int i = 0; i < length2; ++i) {
		int n;
		cin >> n;
		v2.push_back(n);
	}



	int count = 0;

	int min = 1000;
	for (int o : v2) {
		min = (o < min) ? o : min;
	}
	
	int totalLCM = 1;
	for (int o : v1) {
		totalLCM = lcm(totalLCM , o);
		if (totalLCM > min) {
			cout << 0;
			return 0;
		}
	}

	for (int i = 1; i*totalLCM <= min; i++) {
		int flag = 0;
		
		for (int o: v2) {
			flag |= (o % (i*totalLCM));
		}

		if (!flag) {
			count++;
		}
	}

	cout << count;
}
