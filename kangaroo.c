#include <iostream>

using namespace std;

int main() { 
	int x1, v1, x2, v2;
	cin >> x1 >> v1 >> x2 >> v2;


	double res = (double)(x1 - x2)/(v2 - v1);
	if (res != (int)res || res < 0 || v2 - v1 == 0 ) printf("NO");
	else printf("YES");

}
