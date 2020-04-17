#include <iostream> 
#include <vector>
using namespace std;


int main() {
	
	int year;
	cin >> year;

	if (year == 1918) {
		//if Feb 14 == 32nd day of the year
		printf("26.09.1918");
		
	} else if (year > 1918) {
		//using gregorian calender
		int day = 13;

		//if a leap year remove an extra day
		if (((year % 4 == 0) && (year % 100)) || (year % 400) == 0) {
			day--;
		}
		printf("%d.09.%d", day, year);
	} else {

		int day = 13;
		//using julian calender 

		if (year % 4 == 0) {
			day--;
		}
		printf("%d.09.%d", day, year);
	}
}
