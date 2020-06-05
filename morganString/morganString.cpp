/*
 * Puzzle Link: https://www.hackerrank.com/challenges/morgan-and-a-string/problem
 * Puzzle Difficulty: Expert
 *
 * Initial Thoughts:
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
    int testCases; cin >> testCases;
    while(testCases--){
        string a,b; cin >> a >> b;
        string result;
        while(a.size() && b.size() ){
            if (a[0] < b[0]) {
                result+=a[0];
                a.erase(0,1);
            } else if (a[0] == b[0]){
                int j = 1;
                bool flag = true;
                while ( j != (int)std::min(a.size(), b.size())){
                    if (a[j] != b[j]) {
                        flag = false;
                        break;
                    }
                    j++;
                }
                if (flag){
                    if (std::min(a.size(),b.size()) == a.size()){
                        result+=a[0];
                        a.erase(0,1);    
                    } else{
                        result+= b[0];
                        b.erase(0,1);
                    }
                } else if ( a[j] < b[j]) {
                    result+=a[0];
                    a.erase(0,1);    
                } else {
                    result+= b[0];
                    b.erase(0,1);
                }
            } else {
                result+=b[0];
                b.erase(0,1);
            }
        }
        result += b;
        result += a;
        cout << result << endl;
    }
}

