#include <iostream>
#include <string>
using namespace std;
int main(){
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << a.size() << ' ' << b.size() << endl;
	cout << a+b << endl;
	int tmp = a[0];
	a[0] = b[0];
	b[0] = tmp;
	cout << a << " " << b<< endl;
	return 0;
}
