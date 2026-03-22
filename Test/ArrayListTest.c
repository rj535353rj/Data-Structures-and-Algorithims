#include "ArrayListTest.h"
#include <stdio.h>

ArrayList_methods( Integer )

int main () {
	ArrayList__Integer list;
	ArrayList__Integer* plist = &list;
	ArrayList__Integer__constructor( plist );
	ArrayList__Integer__pushBack( plist, 1 );
	ArrayList__Integer__pushBack( plist, 2 );
	ArrayList__Integer__pushBack( plist, 3 );
	ArrayList__Integer__pushBack( plist, 4 );
	ArrayList__Integer__pushBack( plist, 5 );
	ArrayList__Integer__pushBack( plist, 6 );
	ArrayList__Integer__popBack( plist );
	ArrayList__Integer__remove( plist, 0 );
	printf( "%d\n", ArrayList__Integer__get( &list, 0 ) );
}
