#include <bits/stdc++.h>

using namespace std;

int magicSquareRecur(<vector<vector<int>> s,){
		
}

// Complete the formingMagicSquare function below.
int formingMagicSquare(vector<vector<int>> s) {
	//choose a number to be "1"
	//this leaves only a few choices for a number to be "2"
	//due to the constraint that 1-2-3 must never be on the same row/col/diag
	//similar logic follows for 9-8-7
	//meaning 4-5-6 is very easy to check
	//compute the smallest absolute difference in magic square	
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

