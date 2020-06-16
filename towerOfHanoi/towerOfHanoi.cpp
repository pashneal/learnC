/*
 * Puzzle Link: https://www.hackerrank.com/challenges/gena/problem
 * Puzzle Difficulty: Medium
 *
 * Initial Thoughts:
 *	Might not be able to do any better than a bfs to find the minimum number o fmoves until solve
 *
 */
#include <bitset>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <map>
#include <stack>
#include <unordered_map>
#include <math.h>
#define INF 0x7FFFFFFF
#define INFL 0x7FFFFFFFFFFFFFFF
typedef std::pair<int, int> ipair;
typedef std::vector<int> board;
using namespace std;

int main() {
	const int RODS = 4;
	int numberDisks; cin >> numberDisks;
	unordered_set<long>visited;
	board solved(RODS, 0);
	solved[0] = (1 << numberDisks ) - 1;

	vector< board >newBoards;
	vector< board >nextBoards;
	board nextBoard(RODS, 0);
	for (int i = 0 ; i < numberDisks; i++){
		int loc; cin >> loc; loc--;
		nextBoard[loc] |= 1 <<(i);
	}
	nextBoards.push_back(nextBoard);
	bool foundSolution = false;

	int moves = 0;
	//use a BFS solution with bitboards to efficiently find the tower of Hanoi moves
	while (!foundSolution){
		moves++;
		for (auto& nextBoard: nextBoards){
			// for every i,j in rods make the move i->j if legal
			for (int i = 0; i < RODS && !foundSolution; i++){
				int nextSmallest = nextBoard[i] & -nextBoard[i];

				for (int j = 0; j < RODS; j++){
					if (j == i) continue;
					board newBoard = nextBoard;
					//remove from i
					newBoard[i] ^= nextSmallest;

					//if the move is legal make it
					int newSmallest = newBoard[j] & -newBoard[j];
					if (newSmallest && nextSmallest > newSmallest) continue;
					//insert into j
					newBoard[j] ^= nextSmallest;

					//clever little trick to reduce number of states
					//the 2nd, 3rd, and 4th positions can be swapped without
					//changing the minimal distance to solution
					//so if we sort, we reduce all those (3! = 6) permutations to one
					//unique state
					std::sort(newBoard.begin() + 1, newBoard.end());

					//check visited by combining bitboards and storing as hash
					long test = 0;
					for (auto newRod: newBoard){
						test <<= numberDisks;
						test |= newRod;
					}
					if (visited.find(test) != visited.end()) continue;

					visited.insert(test);
					if (solved == newBoard) foundSolution = true;
					newBoards.push_back(newBoard);
				}
			}
		}
		nextBoards = newBoards;
		newBoards.clear();
	}
	cout << moves;
}


