#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

bool check(int a[][3]) {
	//check horizontal
	for (int i = 0 ; i < 3 ; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == 0) {
				sum = 15;
				break;
			}
			sum += a[i][j];
		}
		if (sum != 15) return false;
	}
	//check vertical
	for (int i = 0 ; i < 3 ; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			if (a[j][i] == 0) {
				sum = 15;
				break;
			}
			sum += a[j][i];
		}
		if (sum != 15) return false;
	}

	int sum = 0;
	//check first diagonal
	for (int i = 0; i < 3; i++){
		if (a[i][i] == 0) {
			sum = 15;
			break;
		}
		sum += a[i][i];
	}
	if (sum != 15) return false;

	//check second diagonal
	sum = 0;
	for (int i = 0; i < 3; i++){
		if (a[2-i][i] == 0) {
			sum = 15;
			break;
		}
		sum += a[2-i][i];
	}

	if (sum != 15) return false;

	return true;
}
void permute(int a[][3], std::unordered_set<int>& allowed, int index) {
	if (check(a) && index == 9) 
	{
		std::cout<< "{" <<std::endl;
		for (int i = 0; i < 3; i++) {
			std::cout << "{";
			for (int j = 0; j < 3; j++) {
				printf("%d, ",a[i][j]);
			}
			std::cout << "},";
			std::cout << std::endl;
		}
		std::cout<< "}," << std::endl;
		std::cout << std::endl;
	}

	if (check(a) == false) 
		return;
	std::unordered_set<int>s= allowed;
	for (int i : s) {
		a[index%3][index/3] = i;
		allowed.erase(i);
		permute(a, allowed, index+1);
		allowed.insert(i);
		a[index%3][index/3] = 0;
	}
}
int main() {
	//int  a[3][3] = {{0}};
	//std::unordered_set <int> allowed = {1,2,3,4,5,6,7,8,9};
	//permute(a, allowed, 0);
	//used above to find magic squares below

	
	std::vector <std::vector <int>> magicSquares = {
		{ 8, 3, 4,  1, 5, 9,  6, 7, 2, },

		{ 8, 1, 6,  3, 5, 7,  4, 9, 2, },

		{ 6, 1, 8,  7, 5, 3,  2, 9, 4, },

		{ 6, 7, 2,  1, 5, 9,  8, 3, 4, },

		{ 4, 9, 2,  3, 5, 7,  8, 1, 6, },

		{ 4, 3, 8,  9, 5, 1,  2, 7, 6, },

		{ 2, 7, 6,  9, 5, 1,  4, 3, 8, },

		{ 2, 9, 4,  7, 5, 3,  6, 1, 8, },
	};

	int a[9];
	for (int i =0 ; i < 9 ; i++) {
		std::cin >> a[i];
	}

	int mindiff = 100;
	for (std::vector<int> magic : magicSquares){
		int diff = 0;
		for (int i = 0 ; i < 9; i++) {
			diff += std::abs(a[i] - magic[i]);
		}
		if (mindiff > diff) {
			mindiff = diff;
		}
	}

	std::cout << mindiff << std::endl;

}
