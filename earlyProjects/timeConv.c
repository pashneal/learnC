#include <string>
#include <iostream>

using namespace std;

int main() {
	string timestamp;
	cin >> timestamp;

	string hour = timestamp.substr(0,2);
	string meridiem = timestamp.substr(8,2);

	int hourInt = stoi(hour);

	if  (meridiem.compare("PM") == 0 && hourInt != 12) {
		hourInt += 12;
		hour = to_string(hourInt);
	} else if ( meridiem.compare("AM") == 0 && hourInt == 12) {
		hour = "00";
	}
	
	cout << hour << timestamp.substr(2,6);
}
