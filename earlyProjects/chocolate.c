#include <map>
#include <vector>
#include <iostream>
using namespace std;
int max(int a, int b) { return (a >b) ? a : b; } 
int bestChocolate(int i, vector<int> v, map<int, int> dp, int m, int d){

	if (dp.find(i) != dp.end()) return dp[i];
	if (i + m > v.size()) return 0;


	int sum = 0;

	for (int j = 0; j < m; j++) {
		sum += v[i+j];
	}

	int best;
	if (sum == d) best = max( 1 + bestChocolate(i+m,v,dp,m,d), bestChocolate(i+1,v,dp,m,d));
	else best = bestChocolate(i+1,v,dp,m,d);
	dp[i] = best;
	return best;
}
int main() {

	int length;
	cin >> length;
	
	vector<int> v; 
	int n;
	
	for (int i = 0; i< length; ++i){
		cin >> n;
		v.push_back(n);
	}

	int m , d;
	cin >> d >> m;

	map<int, int> dp;	
	
	cout << bestChocolate(0, v, dp, m, d);
	
}
