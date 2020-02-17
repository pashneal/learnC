#include <stdio.h>
#include <algorithm>

void update(int *a, int *b){ 

	int tmp = *a;
	*a = *a + *b;
	*b = std::abs(*b - tmp);
}
