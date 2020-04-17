#include <iostream>

using namespace std;

int main() {
	int length;
	cin >> length;

	for (int i = 0; i < length ; i++){
		int grade;
		cin >> grade;
		int round = 5 - grade % 5;
		round = (grade < 35) ? 0 : round;
		round = (round >= 3) ? 0 : round;
		grade += round;
		cout << grade << endl;
	}
}
