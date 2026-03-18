#include <stdbool.h>
#include <stdio.h>
#include "checkIfSorted.h"

int main () {
	int t1[5] = {1,2,3,4,5};
	int t2[5] = {1,4,3,5,2};
	int t3[10] = {2,4,6,8,10,12,14,16,18,20};

	printf("%d\n", checkIfSortedOne(t1, t1+5));
	printf("%d\n", checkIfSortedTwo(t1, 5));
	printf("%d\n", checkIfSortedOne(t2, t2+5));
	printf("%d\n", checkIfSortedTwo(t2, 5));
	printf("%d\n", checkIfSortedOne(t3, t3+10));
	printf("%d\n", checkIfSortedTwo(t3, 10));
}
