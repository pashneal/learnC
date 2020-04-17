#include <iostream>

int main(){
	int bookPagesLength;
	std::cin >> bookPagesLength;
	
	int targetPage;
	std::cin >> targetPage;
	int pageTurnsFromFront = targetPage/2;
	int pageTurnsFromBack = bookPagesLength/2 - targetPage/2;
	std::cout << std::min(pageTurnsFromBack, pageTurnsFromFront);
}

