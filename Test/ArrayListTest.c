#include "ArrayListTest.h"
#include <stdio.h>

ArrayList_methods( Integer )

int main () {
	ArrayList__Integer list;
	ArrayList__Integer__constructor( *list );
	ArrayList__Integer__insert( *list, 10, 0);
	ArrayList__Integer__insert( *list, 20, 0);

	printf( "%d\n", ArrayList__Integer__contains( *list, 10 ) );
#define pplication( type, name ) ArrayList__ ## type ## __ ## name
}
