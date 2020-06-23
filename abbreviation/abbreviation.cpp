#include <bits/stdc++.h>
#define INF 0x7fffffff
using namespace std;
long LCS(vector<vector<long>>& dp, string& a, string& b, long i, long j){
    if (j == (long)b.size()) return 0;
    if (i == (long)a.size()) return 0;
    if (dp[i][j] > -1) return dp[i][j];
    dp[i][j] = -INF;
    if (a[i] == b[j]) dp[i][j] = 1 + LCS(dp, a, b, i+1, j+1);
    dp[i][j] = max(dp[i][j] , LCS(dp, a, b, i+1, j));
    return dp[i][j];
}

bool capitalsMatch( string& a, string& b, long i, long j){
    if (i == (long)a.size()) return true;
    if (j == (long)b.size()) return false; 
    if (a[i] == b[j]) return capitalsMatch(a ,b , i+1, j+1);
    else return capitalsMatch(a, b, i, j+1);
}


// Complete the abbreviation function below.
string abbreviation(string a, string b) {
        vector<vector<long>>dp(a.size() ,   vector<long>(b.size(), -1));
        string aa = "";
        for (auto i: a)
            if (i == toupper(i))
                aa+= i;
        if (!capitalsMatch(aa,b,0,0)) {
			return "NO";
        } 
		aa = "";
        for (auto i : a) aa += toupper(i);
        if (LCS(dp, aa, b, 0, 0) == (long) b.size())
			return "YES";
		return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

