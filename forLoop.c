#include <iostream>
#include <cstdio>

using namespace std;

int main () {
	char charray[10][6]={"", "one" ,"two" ,"three" ,"four" ,"five" ,"six" ,"seven" ,"eight" ,"nine" };
	int n;
	int b;
	cin >> n;
	cin >> b;
	for (int x = n; x <= b; x++) {
	
		if (x > 9) {
			if (x % 2 == 0) {
				cout << "even" << endl;
			} else {
				cout << "odd" << endl;
			}
		} else {
			printf("%s\n",charray[x]);
		}
	}
}
