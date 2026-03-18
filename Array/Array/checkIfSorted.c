#include "checkIfSorted.h"
#include <stdbool.h>
#include <stdio.h>


//we iterate over elemnts in the array, starting from the second element, and see if it greater tham the previous element

//method one, using pointers to the start and end of the array

bool checkIfSortedOne ( int* begin, int* end ) {
	int* it = begin;
	++it;
	while (it != end) {
		if( *it < *(it-1) ) {
			return false;
		}
		++it;
	}
	return true;
}

//method two, we use a pointer to the start of the array and the size of the array

bool checkIfSortedTwo ( int* array, int size ) {
	for ( int i = 1; i < size; i++){
		if ( array[i] < array[i-1] ){
			return false;
		}
	}
	return true;
}
