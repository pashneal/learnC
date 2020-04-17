#include <iostream>
#include <vector>

using namespace std;

int main() {
	int nn;
	cin >> nn;

	vector<int> v;

	for (int i = 0; i < nn; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	int m, d;

	cin >> d >> m;
	
	int count = 0;
	int i = 0;
	while (i + m <= nn ) {
		int sum = 0;
		for (int j = 0; j < m; j++){
			sum += v[i+j];
			
		}
		if (d == sum) count++;
		i++;
	}

	cout << count;

}
