#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <functional>

using namespace std;

int main() {
    int lenLeaderBoard;
    cin >> lenLeaderBoard;
    set <int , less<int> > scores;

    for (int i = 0; i < lenLeaderBoard; ++i) {
        int n;
        cin >> n;
        scores.insert(n);
    }

    int alice;
    cin >> alice;
	int size = alice;
    int aliceScores[alice] ;

    
	int n;
    for (int i = 0; i < alice; i++){
        cin >> n;
        aliceScores[i] = n;
    }

    int j ;
    for (int k = 0 ; k < alice; ++k){
		j = scores.size() + 1;
        for (auto i = scores.begin(); i != scores.end(); ++i){
            if ( *i > aliceScores[k]) break;
            j--;    
        }
		cout << j << endl;
    }
    
}    

