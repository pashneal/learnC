/*
 * Puzzle Link: https://www.hackerrank.com/challenges/bear-and-steady-gene/problem
 * Puzzle Difficulty: Medium
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
#include <queue>
using namespace std;
int main() {
    int n; cin >> n;
    string gene ; cin >> gene;
    int avg = n/4;
    unordered_map <char, int>m;
    for (int i = 0 ; i < n; i++){
        if (m.find(gene[i]) == m.end()) m[gene[i]] = 0;
        m[gene[i]]++;
    }
    int total_replace = 0;
    for (auto iter: m) {
        if (iter.second > avg) {
            for (int i = 0 ; i < n; i++) 
                if (gene[i] == iter.first)
                    gene[i] = 'O';
            total_replace += iter.second - avg;
        } else 
            for (int i = 0 ; i < n; i++)
                if (gene[i] == iter.first)
                    gene[i] = '_';
    }
    unsigned long begin = gene.find('O');
    deque<int> found;
    found.push_front(begin);
    
    int minLength = n + 1;
    while (begin < (unsigned long) n){
        if ((int)found.size() == total_replace) {
            minLength = std::min(minLength , (int)begin - found.back() + 1);
            found.pop_back();
        }
        begin = gene.find('O', begin + 1);
        if (begin == (unsigned long)string::npos) break;
        found.push_front(begin);
    }
    cout << ((minLength == n +1 ) ? 0: minLength);
}



