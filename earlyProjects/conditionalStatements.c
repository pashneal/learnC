#include <iostream>
#include <cstdio>

using namespace std;

int main () {
	char charray[10][6]={"", "one" ,"two" ,"three" ,"four" ,"five" ,"six" ,"seven" ,"eight" ,"nine" };
	int n;
	cin >> n;
	if (n > 9) {
		printf("Greater than 9");
	} else {
		printf("%s",charray[n]);
	}

}
