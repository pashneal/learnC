#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n;
	int sum = 0;
	for (int i= 0; i < 3; i++){	
		cin >> n;
		sum+= n;	
	}

	cout << sum;
}
