
/*
 * Puzzle Link: https://www.hackerrank.com/challenges/the-time-in-words/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *        not an algorithmic puzzle so simply map the numbers to words
 *
 */
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <unordered_map>
#include <math.h>
using namespace std;
int main() {
    map<int , string> numberToWords {
        {1,"one"},
        {2,"two"},
        {3,"three"},
        {4,"four"},
        {5,"five"},
        {6,"six"},
        {7,"seven"}, 
        {8,"eight"},
        {9,"nine"},
        {10,"ten"},
        {11,"eleven"},
        {12,"twelve"},
        {13,"thirteen"},
        {14,"fourteen"},
        {15,"quarter"},
        {16,"sixteen"},
        {17,"seventeen"},
        {18,"eighteen"},
        {19,"nineteen"},
        {20,"twenty"},
        {21,"twenty one"},
        {22,"twenty two"},
        {23,"twenty three"},
        {24,"twenty four"},
        {25,"twenty five"},
        {26,"twenty six"},
        {27,"twenty seven"},
        {28,"twenty eight"},
        {29,"twenty nine"},
        {30,"half"},
    };

    int hours, mins; cin >> hours >> mins;
    if ( mins == 0 ) {
        cout << numberToWords[hours] << " o' clock" << endl;
    } else {
        string delimiter = " past ";
        if (mins  > 30) {
			delimiter = " to ";
			mins = 60 - mins;
			hours %= 12;
			hours++;
		}
		if (mins == 1) delimiter = " minute" + delimiter;
		else if (mins % 15) delimiter = " minutes" + delimiter;
        cout << numberToWords[mins] << delimiter << numberToWords[hours] << endl;
    }

}

