#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int num;
	cin >> num;
	int array[num];
	for (int i = num - 1; i >= 0; i--){
		cin >> array[i];
	}
	for (int i = 0; i < num; i++) printf("%d ", array[i]);
    return 0;
}

